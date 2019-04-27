#include "xsection.h"

#include <cmath>

#include <utility>
#define ASSERT_DEFAULT_CONSTRUCTABLE(classname)                  \
  static_assert(std::is_default_constructible<classname>::value, \
                #classname " is not default constructable")

namespace reswmm
{
ASSERT_DEFAULT_CONSTRUCTABLE(circle_xsection);
ASSERT_DEFAULT_CONSTRUCTABLE(trapezoid_xsection);
ASSERT_DEFAULT_CONSTRUCTABLE(rectangle_xsection);
static_assert(std::is_constructible<trapezoid_xsection>::value, "hello");

double xsection::hradius_at_depth(double depth)
{
  return area_at_depth(depth) / perimeter_at_depth(depth);
}

/**
 * @brief Calculate the angle within a circle associated with a depth of flow
 */
static double theta_at_depth(const double diameter, const double depth)
{
  return 2 * std::acos(1 - 2 * depth / diameter);
}

// Circular cross section geometry
double circle_xsection::area_at_depth(const double depth)
{
  const double theta = theta_at_depth(_diameter, depth);
  return std::pow(_diameter, 2) / 8.0 * (theta - std::sin(theta));
}

double circle_xsection::perimeter_at_depth(const double depth)
{
  return theta_at_depth(_diameter, depth) * _diameter / 2;
}

double circle_xsection::top_width_at_depth(const double depth)
{
  return 2 * std::sqrt(depth * (_diameter - depth));
}

double circle_xsection::hradius_at_depth(const double depth)
{
  const double theta = theta_at_depth(_diameter, depth);
  return _diameter / 16 * (1 - std::sin(theta) / theta);
}

// Triangular cross section geometry
double trapezoid_xsection::area_at_depth(const double depth)
{
  return _bottom_width * depth +
         (_slope_left + _slope_right) / 2 * std::pow(depth, 2);
}

double trapezoid_xsection::perimeter_at_depth(const double depth)
{
  return _bottom_width +
         depth * (std::sqrt(1 + std::pow(_slope_left, 2) +
                            std::sqrt(1 + std::pow(_slope_right, 2))));
}

double trapezoid_xsection::top_width_at_depth(const double depth)
{
  return _bottom_width + depth * (_slope_left + _slope_right);
}

}  // namespace reswmm
