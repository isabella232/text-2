#ifndef TEXT_BOOST_CONFIG_HPP
#define TEXT_BOOST_CONFIG_HPP

#if defined(__has_feature) && __has_feature(cxx_relaxed_constexpr)
# define BOOST_CXX14_CONSTEXPR constexpr
#else
# define BOOST_CXX14_CONSTEXPR
#endif

#endif  // TEXT_BOOST_CONFIG_HPP
