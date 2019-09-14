#ifndef TEXT_BOOST_MISMATCH_HPP
#define TEXT_BOOST_MISMATCH_HPP

#include <algorithm>

namespace boost {
namespace algorithm {
template< class InputIt1, class InputIt2 >
std::pair<InputIt1,InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1,
             InputIt2 first2, InputIt2 last2) {
  return std::mismatch(first1, last1, first2, last2);
}
}
}

#endif  // TEXT_BOOST_MISMATCH_HPP
