#ifndef TEXT_BOOST_EQUAL_HPP
#define TEXT_BOOST_EQUAL_HPP

#include <algorithm>

namespace boost {
namespace algorithm {
template< class InputIt1, class InputIt2 >
bool equal(InputIt1 first1, InputIt1 last1,
           InputIt2 first2, InputIt2 last2) {
  return std::equal(first1, last1, first2, last2);
}
}
}

#endif  // TEXT_BOOST_EQUAL_HPP

