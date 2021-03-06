#include <boost/text/collate.hpp>
#include <boost/text/text.hpp>
#include <boost/text/data/da.hpp>

#include <boost/container/flat_set.hpp>
#include <boost/container/flat_map.hpp>

#include <iostream>
#include <unordered_map>
#include <unordered_set>


//[ collation_text_cmp_naive
struct text_cmp
{
    bool operator()(
        boost::text::text const & lhs, boost::text::text const & rhs) const
        noexcept
    {
        // Binary comparison of code point values.
        return std::lexicographical_compare(
            lhs.begin().base(),
            lhs.end().base(),
            rhs.begin().base(),
            rhs.end().base());
    }
};
//]

//[ collation_text_coll_cmp
struct text_coll_cmp
{
    bool operator()(
        boost::text::text const & lhs, boost::text::text const & rhs) const
        noexcept
    {
        return boost::text::collate(lhs, rhs, table) < 0;
    }

    boost::text::collation_table table; // Cheap to copy.
};
//]

//[ collation_text_cmp
struct text_cmp_2
{
    bool operator()(
        boost::text::text const & lhs, boost::text::text const & rhs) const
        noexcept
    {
        // Binary comparison of char values.
        return std::lexicographical_compare(
            lhs.begin().base().base(),
            lhs.end().base().base(),
            rhs.begin().base().base(),
            rhs.end().base().base());
    }
};
//]

int main ()
{

{
//[ collation_simple
boost::text::collation_table default_table =
    boost::text::default_collation_table();

// The Danish town of Arrhus changed the town's name in 2010.  Go figure.
boost::text::text const aarhus_old = u8"Århus";
boost::text::text const aarhus_new = "Aarhus";

// This is fine for one-off comparisons.  Beware though that creating sort
// keys is pretty expensive, and collate() just throws them away after it
// computes its result.
int const collation =
    boost::text::collate(aarhus_old, aarhus_new, default_table);
// "Århus" < "Aarhus" using the default collation, because accents are
// considered after the primary weights of the characters.
assert(0 < collation);

// This is a more common case -- generate keys for your two sequences, keep them
// somewhere, and compare them later.
boost::text::text_sort_key aarhus_new_key =
    boost::text::collation_sort_key(aarhus_new, default_table);
boost::text::text_sort_key aarhus_old_key =
    boost::text::collation_sort_key(aarhus_old, default_table);

assert(aarhus_old_key > aarhus_new_key);
assert(boost::text::compare(aarhus_old_key, aarhus_new_key) > 0);
//]
}

{
//[ collation_simple_tailored
boost::text::collation_table da_table = boost::text::tailored_collation_table(
    boost::text::data::da::standard_collation_tailoring());

boost::text::text const aarhus_old = u8"Århus";
std::array<uint32_t, 6> const aarhus_new = {{'A', 'a', 'r', 'h', 'u', 's'}};

boost::text::text_sort_key aarhus_new_key =
    boost::text::collation_sort_key(aarhus_new, da_table);
boost::text::text_sort_key aarhus_old_key =
    boost::text::collation_sort_key(aarhus_old, da_table);

// Under Danish collation with a default configuration, "Aarhus" < "Århus".
assert(aarhus_old_key < aarhus_new_key);
assert(boost::text::compare(aarhus_old_key, aarhus_new_key) < 0);
//]
}

{
//[ collation_configuration
boost::text::collation_table default_table =
    boost::text::default_collation_table();

// For the boost::text::text "_t" UDL.
using namespace boost::text::literals;

int result = 0;

// No configuration, which implies tertiary strength.
result = boost::text::collate(u8"resume"_t, u8"RÉSUMÉ"_t, default_table);
assert(result < 0);

// Ignore everything but the letters themselves.
result = boost::text::collate(
    u8"resume"_t,
    u8"RÉSUMÉ"_t,
    default_table,
    boost::text::collation_flags::ignore_accents |
        boost::text::collation_flags::ignore_case |
        boost::text::collation_flags::ignore_punctuation);
assert(result == 0);

// Ignore accents; case is still considered of course.
result = boost::text::collate(
    u8"resume"_t,
    u8"Résumé"_t,
    default_table,
    boost::text::collation_flags::ignore_accents);
assert(result < 0);
result = boost::text::collate(
    u8"resume"_t,
    u8"résumé"_t,
    default_table,
    boost::text::collation_flags::ignore_accents);
assert(result == 0);

// Ignore case; accents are still considered of course.
result = boost::text::collate(
    u8"résumé"_t,
    u8"Résumé"_t,
    default_table,
    boost::text::collation_flags::ignore_case);
assert(result == 0);
result = boost::text::collate(
    u8"résumé"_t,
    u8"Resume"_t,
    default_table,
    boost::text::collation_flags::ignore_case);
assert(result > 0);

// Say you want to put one case explicitly before or after the other:
result = boost::text::collate(
    u8"Resume"_t,
    u8"resume"_t,
    default_table,
    boost::text::collation_flags::upper_case_first);
assert(result < 0);
result = boost::text::collate(
    u8"Resume"_t,
    u8"resume"_t,
    default_table,
    boost::text::collation_flags::lower_case_first);
assert(result > 0);

// You can also completely ignore punctuation.
result = boost::text::collate(
    u8"ellipsis"_t,
    u8"ellips...is"_t,
    default_table,
    boost::text::collation_flags::ignore_punctuation);
assert(result == 0);
//]
}

{
//[ collation_set_1
boost::text::collation_table da_table = boost::text::tailored_collation_table(
    boost::text::data::da::standard_collation_tailoring());

boost::text::text const aarhus_old = u8"Århus";
boost::text::text const aarhus_new = u8"Aarhus";

boost::container::flat_multiset<boost::text::text> set1; // So far so good, ...
// set1.insert(aarhus_old);                              // Nope! There's no operator<.

//]

//[ collation_set_2
boost::container::flat_multiset<boost::text::text, text_cmp> set2;
set2.insert(aarhus_old);  // Yay!
set2.insert(aarhus_new);

// Prints "Aarhus Århus", which is not collation-correct.
for (auto const & t : set2) {
    std::cout << t << " ";
}
std::cout << "\n";
//]

//[ collation_set_3
boost::container::flat_multiset<boost::text::text, text_coll_cmp> set3(
    text_coll_cmp{da_table});
set3.insert(aarhus_old);
set3.insert(aarhus_new);

// Prints "Århus Aarhus".  Cool!
for (auto const & t : set3) {
    std::cout << t << " ";
}
std::cout << "\n";
//]

//[ collation_set_4
boost::container::flat_multiset<boost::text::text, text_cmp_2> set4;
set4.insert(aarhus_old);
set4.insert(aarhus_new);

// Prints "Århus Aarhus", which is collation-correct, but only by accident.
// The UTF-8 representation happens to compare that way.
for (auto const & t : set4) {
    std::cout << t << " ";
}
std::cout << "\n";
//]

//[ collation_map
boost::container::flat_multimap<boost::text::text_sort_key, boost::text::text> map;
map.emplace(boost::text::collation_sort_key(aarhus_old, da_table), aarhus_old);
map.emplace(boost::text::collation_sort_key(aarhus_new, da_table), aarhus_new);

// Prints "Århus Aarhus", and performs well.
for (auto const & pair : map) {
    std::cout << pair.second << " ";
}
std::cout << "\n";
//]
}

{
//[ collation_unordered_map
boost::text::collation_table da_table = boost::text::tailored_collation_table(
    boost::text::data::da::standard_collation_tailoring());

boost::text::text const aarhus_old = u8"Århus";
boost::text::text const aarhus_new = u8"Aarhus";

// This works.
std::unordered_multiset<boost::text::text> set;
set.insert(aarhus_old);
set.insert(aarhus_new);
assert(set.size() == 2);

// So does this.
std::unordered_multimap<boost::text::text_sort_key, boost::text::text> map;
map.emplace(boost::text::collation_sort_key(aarhus_old, da_table), aarhus_old);
map.emplace(boost::text::collation_sort_key(aarhus_new, da_table), aarhus_new);
assert(map.size() == 2);

// In fact, hashing support is built in for all the text layer types.
std::unordered_multiset<boost::text::rope> rope_set;
rope_set.insert(boost::text::rope(aarhus_old));
rope_set.insert(boost::text::rope(aarhus_new));
assert(rope_set.size() == 2);

std::unordered_multiset<boost::text::rope_view> rope_view_set;
rope_view_set.insert(aarhus_old);
rope_view_set.insert(aarhus_new);
assert(rope_view_set.size() == 2);

std::unordered_multiset<boost::text::text_view> text_view_set;
text_view_set.insert(aarhus_old);
text_view_set.insert(aarhus_new);
assert(text_view_set.size() == 2);
//]
}

{
//[ collation_sorting_1
boost::text::collation_table da_table = boost::text::tailored_collation_table(
    boost::text::data::da::standard_collation_tailoring());

boost::text::text const aarhus_old = u8"Århus";
boost::text::text const aarhus_new = u8"Aarhus";

std::vector<boost::text::text> text_vec = {aarhus_new, aarhus_old};
// std::sort(text_vec.begin(), text_vec.end()); // Error!  No operator<.
//]

//[ collation_sorting_2
using key_and_text = std::pair<boost::text::text_sort_key, boost::text::text>;
std::vector<key_and_text> key_and_text_vec;
std::transform(
    text_vec.begin(),
    text_vec.end(),
    std::back_inserter(key_and_text_vec),
    [da_table](boost::text::text const & t) {
        return key_and_text(boost::text::collation_sort_key(t, da_table), t);
    });
std::sort(
    key_and_text_vec.begin(),
    key_and_text_vec.end(),
    [](key_and_text const & lhs, key_and_text const & rhs) {
        return lhs.first < rhs.first;
    });

// Prints "Århus Aarhus".
for (auto const & pair : key_and_text_vec) {
    std::cout << pair.second << " ";
}
std::cout << "\n";
//]
}

}
