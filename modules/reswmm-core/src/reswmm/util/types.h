/**
 * @file types.h
 * @brief Common type patterns
 */

#ifndef RESWMM_UTIL_TYPES_H
#define RESWMM_UTIL_TYPES_H

namespace reswmm {
namespace util {
  template <typename T> T make();

  template <typename L, typename R>
  struct multiply {
    typedef decltype(make<L>()*make<R>()) result_type;
  };

  template <typename T, int N>
  struct power {
    typedef decltype(make<T>()*make<typename power<T, N-1>::result_type>()) result_type;
  };

  template <typename T>
  struct power<T, 1> {
    typedef T result_type;
  };

  template <typename L, typename R>
  struct divide {
    typedef decltype(make<L>()*make<R>()) result_type;
  };
}
}

#endif // RESWMM_UTIL_TYPES_H
