#ifndef BOOST_TEXT_DETAIL_BTREE_HPP
#define BOOST_TEXT_DETAIL_BTREE_HPP

#include <boost/text/detail/utility.hpp>

#include <boost/align/align.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <boost/align/aligned_delete.hpp>
#include <boost/container/static_vector.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>

#include <atomic>
#include <vector>


namespace boost { namespace text { namespace detail {

    template<typename T>
    struct node_t;
    template<typename T>
    struct leaf_node_t;
    template<typename T>
    struct interior_node_t;
    template<typename T>
    struct node_ptr;

    template<typename T>
    struct node_ptr
    {
        node_ptr() noexcept : ptr_() {}
        explicit node_ptr(node_t<T> const * node) noexcept : ptr_(node) {}

        explicit operator bool() const noexcept { return ptr_.get(); }

        node_t<T> const * operator->() const noexcept { return ptr_.get(); }

        leaf_node_t<T> const * as_leaf() const noexcept;
        interior_node_t<T> const * as_interior() const noexcept;

        node_t<T> const * get() const noexcept { return ptr_.get(); }

        node_ptr<T> write() const;

        void swap(node_ptr & rhs) noexcept { ptr_.swap(rhs.ptr_); }

        bool operator==(node_ptr const & rhs) const noexcept
        {
            return ptr_ == rhs.ptr_;
        }

        leaf_node_t<T> * as_leaf() noexcept;
        interior_node_t<T> * as_interior() noexcept;

    private:
        intrusive_ptr<node_t<T> const> ptr_;
    };

    template<typename T>
    struct reference
    {
        reference(
            node_ptr<T> const & node,
            std::ptrdiff_t lo,
            std::ptrdiff_t hi) noexcept;

        node_ptr<T> vec_;
        std::ptrdiff_t lo_;
        std::ptrdiff_t hi_;
    };

    template<typename T>
    void * placement_address(void * buf, std::size_t buf_size) noexcept
    {
        std::size_t const alignment = alignof(T);
        std::size_t const size = sizeof(T);
        return alignment::align(alignment, size, buf, buf_size);
    }

    template<typename T>
    struct node_t
    {
        explicit node_t(bool leaf) noexcept : leaf_(leaf) { refs_ = 0; }
        node_t(node_t const & rhs) noexcept : leaf_(rhs.leaf_) { refs_ = 0; }
        node_t & operator=(node_t const & rhs) = delete;

        mutable std::atomic<int> refs_;
        bool leaf_;
    };

    constexpr int min_children = 8;
    constexpr int max_children = 16;

    template<typename T>
    inline std::ptrdiff_t size(node_t<T> const * node) noexcept;

    using keys_t = container::static_vector<std::ptrdiff_t, max_children>;

    template<typename T>
    using children_t = container::static_vector<node_ptr<T>, max_children>;

    static_assert(sizeof(std::ptrdiff_t) * 8 <= 64, "");

    template<typename T>
    struct interior_node_t : node_t<T>
    {
        interior_node_t() noexcept : node_t<T>(false) {}

        void * operator new(std::size_t) = delete;

        alignas(64) keys_t keys_;
        children_t<T> children_;
    };

    template<typename T>
    inline interior_node_t<T> * new_interior_node()
    {
        void * ptr = alignment::aligned_alloc(
            alignof(interior_node_t<T>), sizeof(interior_node_t<T>));
        return ::new (ptr) interior_node_t<T>;
    }

    template<typename T>
    inline interior_node_t<T> *
    new_interior_node(interior_node_t<T> const & other)
    {
        void * ptr = alignment::aligned_alloc(
            alignof(interior_node_t<T>), sizeof(interior_node_t<T>));
        return ::new (ptr) interior_node_t<T>(other);
    }

    template<typename T>
    constexpr int node_buf_size() noexcept
    {
        return max_(alignof(std::vector<T>), alignof(reference<T>)) +
               max_(sizeof(std::vector<T>), sizeof(reference<T>));
    }

    template<typename T>
    struct leaf_node_t : node_t<T>
    {
        enum class which : char { vec, ref };

        leaf_node_t() noexcept : leaf_node_t(std::vector<T>()) {}

        leaf_node_t(std::vector<T> const & t) :
            node_t<T>(true),
            buf_ptr_(nullptr),
            which_(which::vec)
        {
            auto at = placement_address<std::vector<T>>(buf_, sizeof(buf_));
            BOOST_ASSERT(at);
            buf_ptr_ = new (at) std::vector<T>(t);
        }

        leaf_node_t(std::vector<T> && t) noexcept :
            node_t<T>(true),
            buf_ptr_(nullptr),
            which_(which::vec)
        {
            auto at = placement_address<std::vector<T>>(buf_, sizeof(buf_));
            BOOST_ASSERT(at);
            buf_ptr_ = new (at) std::vector<T>(std::move(t));
        }

        leaf_node_t(leaf_node_t const & rhs) :
            node_t<T>(true),
            buf_ptr_(rhs.buf_ptr_),
            which_(rhs.which_)
        {
            switch (which_) {
            case which::vec: {
                auto at = placement_address<std::vector<T>>(buf_, sizeof(buf_));
                BOOST_ASSERT(at);
                buf_ptr_ = new (at) std::vector<T>(rhs.as_vec());
                break;
            }
            case which::ref: {
                auto at = placement_address<reference<T>>(buf_, sizeof(buf_));
                BOOST_ASSERT(at);
                buf_ptr_ = new (at) reference<T>(rhs.as_reference());
                break;
            }
            default: BOOST_ASSERT(!"unhandled leaf node case"); break;
            }
        }

        leaf_node_t & operator=(leaf_node_t const &) = delete;
        leaf_node_t(leaf_node_t &&) = delete;
        leaf_node_t & operator=(leaf_node_t &&) = delete;

        ~leaf_node_t() noexcept
        {
            if (!buf_ptr_)
                return;

            switch (which_) {
            case which::vec: as_vec().~vector(); break;
            case which::ref: as_reference().~reference(); break;
            default: BOOST_ASSERT(!"unhandled leaf node case"); break;
            }
        }

        int size() const noexcept
        {
            switch (which_) {
            case which::vec: return as_vec().size(); break;
            case which::ref:
                return as_reference().hi_ - as_reference().lo_;
                break;
            default: BOOST_ASSERT(!"unhandled leaf node case"); break;
            }
            return -(1 << 30); // This should never execute.
        }

        std::vector<T> const & as_vec() const noexcept
        {
            BOOST_ASSERT(which_ == which::vec);
            return *static_cast<std::vector<T> *>(buf_ptr_);
        }

        reference<T> const & as_reference() const noexcept
        {
            BOOST_ASSERT(which_ == which::ref);
            return *static_cast<reference<T> *>(buf_ptr_);
        }

        std::vector<T> & as_vec() noexcept
        {
            BOOST_ASSERT(which_ == which::vec);
            return *static_cast<std::vector<T> *>(buf_ptr_);
        }

        reference<T> & as_reference() noexcept
        {
            BOOST_ASSERT(which_ == which::ref);
            return *static_cast<reference<T> *>(buf_ptr_);
        }

        char buf_[node_buf_size<T>()];
        void * buf_ptr_;
        which which_;
    };

    template<typename T>
    inline leaf_node_t<T> const * node_ptr<T>::as_leaf() const noexcept
    {
        BOOST_ASSERT(ptr_);
        BOOST_ASSERT(ptr_->leaf_);
        return static_cast<leaf_node_t<T> const *>(ptr_.get());
    }

    template<typename T>
    inline interior_node_t<T> const * node_ptr<T>::as_interior() const noexcept
    {
        BOOST_ASSERT(ptr_);
        BOOST_ASSERT(!ptr_->leaf_);
        return static_cast<interior_node_t<T> const *>(ptr_.get());
    }

    template<typename T>
    inline node_ptr<T> node_ptr<T>::write() const
    {
        if (ptr_->leaf_)
            return node_ptr<T>(new leaf_node_t<T>(*as_leaf()));
        else
            return node_ptr<T>(new_interior_node(*as_interior()));
    }

    template<typename T>
    inline leaf_node_t<T> * node_ptr<T>::as_leaf() noexcept
    {
        BOOST_ASSERT(ptr_);
        BOOST_ASSERT(ptr_->leaf_);
        return const_cast<leaf_node_t<T> *>(
            static_cast<leaf_node_t<T> const *>(ptr_.get()));
    }

    template<typename T>
    inline interior_node_t<T> * node_ptr<T>::as_interior() noexcept
    {
        BOOST_ASSERT(ptr_);
        BOOST_ASSERT(!ptr_->leaf_);
        return const_cast<interior_node_t<T> *>(
            static_cast<interior_node_t<T> const *>(ptr_.get()));
    }

    // These functions were implemented following the "Reference counting"
    // example from Boost.Atomic.

    template<typename T>
    inline void intrusive_ptr_add_ref(node_t<T> const * node)
    {
        node->refs_.fetch_add(1, std::memory_order_relaxed);
    }

    template<typename T>
    inline void intrusive_ptr_release(node_t<T> const * node)
    {
        if (node->refs_.fetch_sub(1, std::memory_order_release) == 1) {
            std::atomic_thread_fence(std::memory_order_acquire);
            if (node->leaf_)
                delete static_cast<leaf_node_t<T> const *>(node);
            else
                alignment::aligned_delete{}((interior_node_t<T> *)(node));
        }
    }

    template<typename T>
    inline std::ptrdiff_t size(node_t<T> const * node) noexcept
    {
        if (!node) {
            return 0;
        } else if (node->leaf_) {
            return static_cast<leaf_node_t<T> const *>(node)->size();
        } else {
            auto int_node = static_cast<interior_node_t<T> const *>(node);
            if (int_node->keys_.empty())
                return 0;
            return int_node->keys_.back();
        }
    }

    template<typename T>
    inline children_t<T> const & children(node_ptr<T> const & node) noexcept
    {
        return node.as_interior()->children_;
    }

    template<typename T>
    inline children_t<T> & children(node_ptr<T> & node) noexcept
    {
        return node.as_interior()->children_;
    }

    template<typename T>
    inline keys_t const & keys(node_ptr<T> const & node) noexcept
    {
        return node.as_interior()->keys_;
    }

    template<typename T>
    inline keys_t & keys(node_ptr<T> & node) noexcept
    {
        return node.as_interior()->keys_;
    }

    template<typename T>
    inline int num_children(node_ptr<T> const & node) noexcept
    {
        return static_cast<int>(children(node).size());
    }

    template<typename T>
    inline int num_keys(node_ptr<T> const & node) noexcept
    {
        return static_cast<int>(keys(node).size());
    }

    template<typename T>
    inline bool full(node_ptr<T> const & node) noexcept
    {
        return num_children(node) == max_children;
    }

    template<typename T>
    inline bool almost_full(node_ptr<T> const & node) noexcept
    {
        return num_children(node) == max_children - 1;
    }

    template<typename T>
    inline bool leaf_children(node_ptr<T> const & node)
    {
        return children(node)[0]->leaf_;
    }

    template<typename T>
    inline std::ptrdiff_t
    offset(interior_node_t<T> const * node, int i) noexcept
    {
        BOOST_ASSERT(0 <= i);
        BOOST_ASSERT(i <= (int)node->keys_.size());
        if (i == 0)
            return 0;
        return node->keys_[i - 1];
    }

    template<typename T>
    inline std::ptrdiff_t offset(node_ptr<T> const & node, int i) noexcept
    {
        return offset(node.as_interior(), i);
    }

    template<typename T>
    inline std::ptrdiff_t
    find_child(interior_node_t<T> const * node, std::ptrdiff_t n) noexcept
    {
        int i = 0;
        auto const sizes = static_cast<int>(node->keys_.size());
        while (i < sizes - 1 && node->keys_[i] <= n) {
            ++i;
        }
        BOOST_ASSERT(i < sizes);
        return i;
    }

    template<typename T>
    struct found_leaf
    {
        node_ptr<T> const * leaf_;
        std::ptrdiff_t offset_;
        alignas(
            64) container::static_vector<interior_node_t<T> const *, 24> path_;

        static_assert(sizeof(interior_node_t<T> const *) * 8 <= 64, "");
    };

    template<typename T, typename LeafFunc, typename IntFunc>
    inline void visit_path_to_leaf(
        node_ptr<T> const & node,
        std::ptrdiff_t n,
        LeafFunc const & leaf_func,
        IntFunc const & int_func) noexcept
    {
        BOOST_ASSERT(node);
        BOOST_ASSERT(n <= size(node.get()));
        if (node->leaf_) {
            leaf_func(node, n);
            return;
        }
        auto const i = find_child(node.as_interior(), n);
        node_ptr<T> const & child = children(node)[i];
        auto const offset_ = offset(node, i);
        int_func(node, n);
        visit_path_to_leaf(child, n - offset_, leaf_func, int_func);
    }

    template<typename T>
    inline void find_leaf(
        node_ptr<T> const & node,
        std::ptrdiff_t n,
        found_leaf<T> & retval) noexcept
    {
        auto leaf_func = [&retval](node_ptr<T> const & node, std::ptrdiff_t n) {
            retval.leaf_ = &node;
            retval.offset_ = n;
        };
        auto int_func = [&retval](node_ptr<T> const & node, std::ptrdiff_t) {
            retval.path_.push_back(node.as_interior());
        };
        visit_path_to_leaf(node, n, leaf_func, int_func);
    }

    template<typename T>
    struct found_element
    {
        found_leaf<T> leaf_;
        T const * element_;
    };

    template<typename T>
    inline void find_element(
        node_ptr<T> const & node,
        std::ptrdiff_t n,
        found_element<T> & retval) noexcept
    {
        BOOST_ASSERT(node);
        find_leaf(node, n, retval.leaf_);

        leaf_node_t<T> const * leaf = retval.leaf_.leaf_->as_leaf();
        T const * e = nullptr;
        switch (leaf->which_) {
        case leaf_node_t<T>::which::vec:
            e = &leaf->as_vec()[retval.leaf_.offset_];
            break;
        case leaf_node_t<T>::which::ref:
            e = &leaf->as_reference().vec_.as_leaf()->as_vec()
                     [leaf->as_reference().lo_ + retval.leaf_.offset_];
            break;
        default: BOOST_ASSERT(!"unhandled leaf node case"); break;
        }
        retval.element_ = e;
    }

    template<typename T>
    inline reference<T>::reference(
        node_ptr<T> const & vec_node,
        std::ptrdiff_t lo,
        std::ptrdiff_t hi) noexcept :
        vec_(vec_node),
        lo_(lo),
        hi_(hi)
    {
        BOOST_ASSERT(vec_node);
        BOOST_ASSERT(vec_node->leaf_);
        BOOST_ASSERT(vec_node.as_leaf()->which_ == leaf_node_t<T>::which::vec);
    }

    template<typename T>
    inline node_ptr<T> make_node(std::vector<T> const & t)
    {
        return node_ptr<T>(new leaf_node_t<T>(t));
    }

    template<typename T>
    inline node_ptr<T> make_node(std::vector<T> && t)
    {
        return node_ptr<T>(new leaf_node_t<T>(std::move(t)));
    }

    template<typename T>
    inline node_ptr<T>
    make_ref(leaf_node_t<T> const * v, std::ptrdiff_t lo, std::ptrdiff_t hi)
    {
        BOOST_ASSERT(v->which_ == leaf_node_t<T>::which::vec);
        leaf_node_t<T> * leaf = nullptr;
        node_ptr<T> retval(leaf = new leaf_node_t<T>);
        leaf->which_ = leaf_node_t<T>::which::ref;
        auto at =
            placement_address<reference<T>>(leaf->buf_, sizeof(leaf->buf_));
        BOOST_ASSERT(at);
        leaf->buf_ptr_ = new (at) reference<T>(node_ptr<T>(v), lo, hi);
        return retval;
    }

    template<typename T>
    inline node_ptr<T>
    make_ref(reference<T> const & r, std::ptrdiff_t lo, std::ptrdiff_t hi)
    {
        auto const offset = r.lo_;
        return make_ref(r.vec_.as_leaf(), lo + offset, hi + offset);
    }

    template<typename T, typename Fn>
    void foreach_leaf(node_ptr<T> const & root, Fn && f)
    {
        if (!root)
            return;

        std::ptrdiff_t offset = 0;
        while (true) {
            found_leaf<T> found;
            find_leaf(root, offset, found);
            leaf_node_t<T> const * leaf = found.leaf_->as_leaf();

            if (!f(leaf))
                break;

            if ((offset += size(leaf)) == size(root.get()))
                break;
        }
    }

    template<typename Iter>
    struct reversed_range
    {
        Iter first_;
        Iter last_;

        Iter begin() const noexcept { return first_; }
        Iter end() const noexcept { return last_; }
    };

    template<typename Container>
    reversed_range<typename Container::const_reverse_iterator>
    reverse(Container const & c) noexcept
    {
        return {c.rbegin(), c.rend()};
    }

    template<typename T>
    inline void
    bump_keys(interior_node_t<T> * node, int from, std::ptrdiff_t bump)
    {
        for (int i = from, size = (int)node->keys_.size(); i < size; ++i) {
            node->keys_[i] += bump;
        }
    }

    template<typename T>
    inline void bump_along_path_to_leaf(
        node_ptr<T> const & node,
        std::ptrdiff_t n,
        std::ptrdiff_t bump) noexcept
    {
        auto leaf_func = [](node_ptr<T> const &, std::ptrdiff_t) {};
        auto int_func = [bump](node_ptr<T> const & node, std::ptrdiff_t n) {
            auto interior =
                const_cast<detail::interior_node_t<T> *>(node.as_interior());
            auto from = find_child(interior, n);
            bump_keys(interior, from, bump);
        };
        visit_path_to_leaf(node, n, leaf_func, int_func);
    }

    template<typename T>
    inline void insert_child(
        interior_node_t<T> * node, int i, node_ptr<T> && child) noexcept
    {
        auto const child_size = size(child.get());
        node->children_.insert(node->children_.begin() + i, std::move(child));
        node->keys_.insert(node->keys_.begin() + i, offset(node, i));
        bump_keys(node, i, child_size);
    }

    enum erasure_adjustments { adjust_keys, dont_adjust_keys };

    template<typename T>
    inline void erase_child(
        interior_node_t<T> * node,
        int i,
        erasure_adjustments adj = adjust_keys) noexcept
    {
        auto const child_size = size(node->children_[i].get());
        node->children_.erase(node->children_.begin() + i);
        node->keys_.erase(node->keys_.begin() + i);
        if (adj == adjust_keys)
            bump_keys(node, i, -child_size);
    }

    template<typename T>
    inline node_ptr<T>
    slice_leaf(node_ptr<T> node, std::ptrdiff_t lo, std::ptrdiff_t hi)
    {
        BOOST_ASSERT(node);
        BOOST_ASSERT(0 <= lo && lo <= size(node.get()));
        BOOST_ASSERT(0 <= hi && hi <= size(node.get()));
        BOOST_ASSERT(lo < hi);

        switch (node.as_leaf()->which_) {
        case leaf_node_t<T>::which::vec:
            return make_ref(node.as_leaf(), lo, hi);
        case leaf_node_t<T>::which::ref: {
            return make_ref(node.as_leaf()->as_reference(), lo, hi);
        }
        default: BOOST_ASSERT(!"unhandled leaf node case"); break;
        }
        return node_ptr<T>(); // This should never execute.
    }

    template<typename T>
    struct leaf_slices
    {
        node_ptr<T> slice;
        node_ptr<T> other_slice;
    };

    template<typename T>
    inline leaf_slices<T>
    erase_leaf(node_ptr<T> node, std::ptrdiff_t lo, std::ptrdiff_t hi)
    {
        BOOST_ASSERT(node);
        BOOST_ASSERT(0 <= lo && lo <= size(node.get()));
        BOOST_ASSERT(0 <= hi && hi <= size(node.get()));
        BOOST_ASSERT(lo < hi);

        auto const leaf_size = size(node.get());

        leaf_slices<T> retval;

        if (lo == 0 && hi == leaf_size)
            return retval;

        if (hi != leaf_size)
            retval.other_slice = slice_leaf(node, hi, leaf_size);
        if (lo != 0)
            retval.slice = slice_leaf(node, 0, lo);

        if (!retval.slice)
            retval.slice.swap(retval.other_slice);

        return retval;
    }

    // Follows CLRS.
    template<typename T>
    inline node_ptr<T> btree_split_child(node_ptr<T> parent, int i)
    {
        BOOST_ASSERT(0 <= i && i < num_children(parent));
        BOOST_ASSERT(!full(parent));
        BOOST_ASSERT(
            full(children(parent)[i]) || almost_full(children(parent)[i]));

        node_ptr<T> retval;

        interior_node_t<T> * new_node = nullptr;
        node_ptr<T> new_node_ptr(new_node = new_interior_node<T>());

        BOOST_ASSERT(!leaf_children(parent));

        {
            node_ptr<T> child = children(parent)[i];
            int const elements = min_children - (full(child) ? 0 : 1);
            new_node->children_.resize(elements);
            std::copy(
                children(child).begin() + min_children,
                children(child).end(),
                new_node->children_.begin());
            new_node->keys_.resize(elements);
            auto it = new_node->children_.begin();
            std::ptrdiff_t sum = 0;
            for (auto & key : new_node->keys_) {
                sum += size(it->get());
                key = sum;
                ++it;
            }
        }

        retval = parent.write();
        children(retval).insert(children(retval).begin() + i + 1, new_node_ptr);

        node_ptr<T> & child = children(retval)[i];
        child = child.write();
        children(child).resize(min_children);
        keys(child).resize(min_children);

        keys(retval).insert(
            keys(retval).begin() + i, offset(retval, i) + size(child.get()));

        return retval;
    }

    // Analogous to btree_split_child(), for leaf nodes.
    template<typename T>
    inline node_ptr<T>
    btree_split_leaf(node_ptr<T> parent, int i, std::ptrdiff_t at)
    {
        BOOST_ASSERT(0 <= i && i < num_children(parent));
        BOOST_ASSERT(0 <= at && at <= size(parent.get()));
        BOOST_ASSERT(!full(parent));

        node_ptr<T> child = children(parent)[i];

        auto const child_size = child.as_leaf()->size();
        auto const offset_at_i = offset(parent, i);
        auto const cut = static_cast<int>(at - offset_at_i);

        if (cut == 0 || cut == child_size)
            return parent;

        node_ptr<T> retval;

        node_ptr<T> right = slice_leaf(child, cut, child_size);
        node_ptr<T> left = slice_leaf(child, 0, cut);

        retval = parent.write();
        children(retval)[i] = left;
        children(retval).insert(children(retval).begin() + i + 1, right);
        keys(retval).insert(keys(retval).begin() + i, offset_at_i + cut);

        return retval;
    }

    // Follows CLRS.
    template<typename T>
    inline node_ptr<T> btree_insert_nonfull(
        node_ptr<T> parent, std::ptrdiff_t at, node_ptr<T> && node)
    {
        BOOST_ASSERT(!parent->leaf_);
        BOOST_ASSERT(0 <= at && at <= size(parent.get()));
        BOOST_ASSERT(node->leaf_);

        int i = find_child(parent.as_interior(), at);
        if (leaf_children(parent)) {
            // Note that this split may add a node to parent, for a
            // maximum of two added nodes in the leaf code path.
            parent = btree_split_leaf(parent, i, at);
            if (keys(parent)[i] <= at)
                ++i;

            parent = parent.write();
            insert_child(parent.as_interior(), i, std::move(node));
        } else {
            {
                node_ptr<T> child = children(parent)[i];
                bool const child_i_needs_split =
                    full(child) || (leaf_children(child) && almost_full(child));
                if (child_i_needs_split) {
                    parent = btree_split_child(parent, i);
                    if (keys(parent)[i] <= at)
                        ++i;
                }
            }
            parent = parent.write();
            auto delta = -size(children(parent)[i].get());
            node_ptr<T> new_child = btree_insert_nonfull(
                children(parent)[i], at - offset(parent, i), std::move(node));
            delta += size(new_child.get());
            children(parent)[i] = new_child;
            for (int j = i, size = num_keys(parent); j < size; ++j) {
                keys(parent)[j] += delta;
            }
        }

        return parent;
    }

    // Follows CLRS.
    template<typename T>
    inline node_ptr<T>
    btree_insert(node_ptr<T> root, std::ptrdiff_t at, node_ptr<T> && node)
    {
        BOOST_ASSERT(0 <= at && at <= size(root.get()));
        BOOST_ASSERT(node->leaf_);

        if (!root) {
            return node;
        } else if (root->leaf_) {
            interior_node_t<T> * new_root = nullptr;
            node_ptr<T> new_root_ptr(new_root = new_interior_node<T>());
            auto const root_size = size(root.get());
            new_root->children_.push_back(root);
            new_root->keys_.push_back(root_size);
            return btree_insert_nonfull(new_root_ptr, at, std::move(node));
        } else if (full(root) || (leaf_children(root) && almost_full(root))) {
            interior_node_t<T> * new_root = nullptr;
            node_ptr<T> new_root_ptr(new_root = new_interior_node<T>());
            auto const root_size = size(root.get());
            new_root->children_.push_back(root);
            new_root->keys_.push_back(root_size);
            new_root_ptr = btree_split_child(new_root_ptr, 0);
            return btree_insert_nonfull(new_root_ptr, at, std::move(node));
        } else {
            return btree_insert_nonfull(root, at, std::move(node));
        }
    }

    // Recursing top-to-bottom, pull nodes down the tree as necessary to
    // ensure that each node has min_children + 1 nodes in it *before*
    // recursing into it.  This enables the erasure to happen in a single
    // downward pass, with no backtracking.  This function only erases
    // entire segments; the segments must have been split appropriately
    // before this function is ever called.
    template<typename T>
    inline node_ptr<T> btree_erase(
        node_ptr<T> node, std::ptrdiff_t at, leaf_node_t<T> const * leaf)
    {
        BOOST_ASSERT(node);

        node_ptr<T> retval;

        auto child_index = find_child(node.as_interior(), at);

        if (leaf_children(node)) {
            if (num_children(node) == 2)
                return children(node)[child_index ? 0 : 1];

            BOOST_ASSERT(children(node)[child_index].as_leaf() == leaf);

            retval = node.write();
            erase_child(retval.as_interior(), child_index);
            return retval;
        }

        retval = node.write();

        node_ptr<T> new_child;

        node_ptr<T> & child = children(retval)[child_index];
        // Due to the use of almost_full() in a few places, == does not
        // actually work here.  As unsatisfying as it is, the minimium
        // possible number of children is actually min_children - 1.
        if (num_children(child) <= min_children) {
            BOOST_ASSERT(
                child_index != 0 || child_index != num_children(retval) - 1);

            if (child_index != 0 &&
                min_children + 1 <=
                    num_children(children(retval)[child_index - 1])) {
                node_ptr<T> & child_left_sib =
                    children(retval)[child_index - 1];

                // Remove last element of left sibling.
                node_ptr<T> moved_node = children(child_left_sib).back();
                auto const moved_node_size = size(moved_node.get());

                child_left_sib = child_left_sib.write();
                erase_child(
                    child_left_sib.as_interior(),
                    num_children(child_left_sib) - 1);

                // Prepend last element onto child; now child has min_children
                // + 1 children, and we can recurse.
                child = child.write();
                insert_child(child.as_interior(), 0, std::move(moved_node));

                std::ptrdiff_t const offset_ = offset(retval, child_index);
                new_child =
                    btree_erase(child, at - offset_ + moved_node_size, leaf);
            } else if (
                child_index != num_children(retval) - 1 &&
                min_children + 1 <=
                    num_children(children(retval)[child_index + 1])) {
                node_ptr<T> & child_right_sib =
                    children(retval)[child_index + 1];

                // Remove first element of right sibling.
                node_ptr<T> moved_node = children(child_right_sib).front();

                child_right_sib = child_right_sib.write();
                erase_child(child_right_sib.as_interior(), 0);

                // Append first element onto child; now child has min_children
                // + 1 children, and we can recurse.
                child = child.write();
                insert_child(
                    child.as_interior(),
                    num_children(child),
                    std::move(moved_node));

                std::ptrdiff_t const offset_ = offset(retval, child_index);
                new_child = btree_erase(child, at - offset_, leaf);
            } else {
                auto const right_index =
                    child_index == 0 ? child_index + 1 : child_index;
                auto const left_index = right_index - 1;

                node_ptr<T> & left = children(retval)[left_index];
                node_ptr<T> & right = children(retval)[right_index];

                left = left.write();
                right = right.write();

                children_t<T> & left_children = children(left);
                children_t<T> & right_children = children(right);

                left_children.insert(
                    left_children.end(),
                    right_children.begin(),
                    right_children.end());

                keys_t & left_keys = keys(left);
                keys_t & right_keys = keys(right);

                auto const old_left_size = left_keys.back();
                int const old_children = num_keys(left);

                left_keys.insert(
                    left_keys.end(), right_keys.begin(), right_keys.end());
                for (int i = old_children, size = num_keys(left); i < size;
                     ++i) {
                    left_keys[i] += old_left_size;
                }

                std::ptrdiff_t const offset_ = offset(retval, left_index);
                new_child = btree_erase(left, at - offset_, leaf);

                // This can only happen if node is the root.
                if (num_children(retval) == 2)
                    return new_child;

                erase_child(
                    retval.as_interior(), right_index, dont_adjust_keys);

                if (right_index <= child_index)
                    --child_index;
            }
        } else {
            std::ptrdiff_t const offset_ = offset(retval, child_index);
            new_child = btree_erase(child, at - offset_, leaf);
        }

        children(retval)[child_index] = new_child;
        std::ptrdiff_t prev_size = 0;
        for (int i = 0, size = num_keys(retval); i < size; ++i) {
            prev_size += detail::size(children(retval)[i].get());
            keys(retval)[i] = prev_size;
        }

        return retval;
    }

    template<typename T>
    inline node_ptr<T>
    btree_erase(node_ptr<T> root, std::ptrdiff_t lo, std::ptrdiff_t hi)
    {
        BOOST_ASSERT(root);
        BOOST_ASSERT(0 <= lo && lo <= size(root.get()));
        BOOST_ASSERT(0 <= hi && hi <= size(root.get()));
        BOOST_ASSERT(lo < hi);

        BOOST_ASSERT(root);

        if (lo == 0 && hi == size(root.get())) {
            return node_ptr<T>();
        } else if (root->leaf_) {
            leaf_slices<T> slices;
            slices = erase_leaf(root, lo, hi);
            if (!slices.other_slice) {
                return slices.slice;
            } else {
                interior_node_t<T> * new_root = nullptr;
                node_ptr<T> new_root_ptr(new_root = new_interior_node<T>());
                new_root->keys_.push_back(size(slices.slice.get()));
                new_root->keys_.push_back(
                    new_root->keys_[0] + size(slices.other_slice.get()));
                new_root->children_.push_back(std::move(slices.slice));
                new_root->children_.push_back(std::move(slices.other_slice));
                return new_root_ptr;
            }
        } else {
            node_ptr<T> retval = root;

            auto const final_size = size(retval.get()) - (hi - lo);

            // Right after the hi-segment, insert the suffix of the
            // hi-segment that's not being erased (if there is one).
            detail::found_leaf<T> found_hi;
            detail::find_leaf(retval, hi, found_hi);
            auto const hi_leaf_size = size(found_hi.leaf_->get());
            if (found_hi.offset_ != 0 && found_hi.offset_ != hi_leaf_size) {
                node_ptr<T> suffix =
                    slice_leaf(*found_hi.leaf_, found_hi.offset_, hi_leaf_size);
                auto const suffix_at = hi - found_hi.offset_ + hi_leaf_size;
                retval = btree_insert(retval, suffix_at, std::move(suffix));
                detail::find_leaf(retval, suffix_at, found_hi);
            }

            // Right before the lo-segment, insert the prefix of the
            // lo-segment that's not being erased (if there is one).
            detail::found_leaf<T> found_lo;
            detail::find_leaf(retval, lo, found_lo);
            if (found_lo.offset_ != 0) {
                auto const lo_leaf_size = size(found_lo.leaf_->get());
                node_ptr<T> prefix =
                    slice_leaf(*found_lo.leaf_, 0, found_lo.offset_);
                if (prefix.get() == found_lo.leaf_->get())
                    hi -= lo_leaf_size;
                retval = btree_insert(
                    retval, lo - found_lo.offset_, std::move(prefix));
                detail::find_leaf(retval, lo, found_lo);
            }

            BOOST_ASSERT(found_lo.offset_ == 0);
            BOOST_ASSERT(
                found_hi.offset_ == 0 || found_hi.offset_ == hi_leaf_size);

            leaf_node_t<T> const * leaf_lo = found_lo.leaf_->as_leaf();
            while (true) {
                retval = btree_erase(retval, lo, leaf_lo);
                BOOST_ASSERT(final_size <= size(retval.get()));
                if (size(retval.get()) == final_size)
                    break;
                found_leaf<T> found;
                find_leaf(retval, lo, found);
                leaf_lo = found.leaf_->as_leaf();
            }

            return retval;
        }
    }

#ifdef BOOST_TEXT_TESTING
    template<typename T>
    void dump_tree(
        std::ostream & os,
        node_ptr<T> const & root,
        int key = -1,
        int indent = 0);

    template<typename T>
    inline int check_sizes(node_ptr<T> const & node, int size)
    {
        if (node->leaf_) {
            auto leaf = node.as_leaf();
            if (leaf->which_ == leaf_node_t<T>::which::vec)
                return leaf->as_vec().size();
            else
                return leaf->as_reference().hi_ - leaf->as_reference().lo_;
        }

        int children_size = 0;
        int prev_key = 0;
        int i = 0;
        for (auto const & child : children(node)) {
            int key = keys(node)[i++];
            children_size += check_sizes(child, key - prev_key);
            prev_key = key;
        }

        if (children_size != size) {
            (void)0; // set breakpoint here
        }
        BOOST_ASSERT(children_size == size);

        return children_size;
    }
#endif

}}}

#endif
