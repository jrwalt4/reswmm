#include "reswmm/util/util.h"

#include <utility>
// std::pair
#include <cmath>
// abs
#include <iostream>
// std::cout
#include <boost/math/tools/roots.hpp>
// boost::math::tools::bisect

namespace reswmm
{
namespace util
{
/**
 * Tolerance function
 */
typedef bool (*tolerance_fn_t)(double low, double high);

static bool tolerance_fn(double low, double high)
{
  static const double ROOT_TOLERANCE = 0.0001;
  return fabs(high - low) < ROOT_TOLERANCE;
}

double find_root(root_fn_t fn, double low, double high)
{
  std::pair<double, double> result;
  boost::uintmax_t max_iter = 100;
  result = boost::math::tools::bisect<root_fn_t, double, tolerance_fn_t>(
      fn, low, high, tolerance_fn, max_iter);
  return (std::get<0>(result) + std::get<1>(result)) / 2;
}

}  // namespace util
}  // namespace reswmm
