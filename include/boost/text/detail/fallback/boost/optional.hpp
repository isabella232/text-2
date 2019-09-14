#ifndef TEXT_BOOST_OPTIONAL_HPP
#define TEXT_BOOST_OPTIONAL_HPP

#include <optional>

namespace boost {
template <typename T>
using optional = std::optional<T>;
}

#endif  // TEXT_BOOST_OPTIONAL_HPP
