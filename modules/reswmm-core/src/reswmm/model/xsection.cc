#include "./xsection.h"

#include "reswmm/units.h"
#include <boost/units/cmath.hpp>

namespace reswmm
{
//using namespace units;
namespace bu = boost::units;

typedef xsection::length_type length_type;
typedef xsection::area_type area_type;
typedef xsection::dimensionless_type dimensionless_type;
typedef units::angle_q angle_type;

length_type xsection::hradius_at_depth(length_type depth)
{
  return area_at_depth(depth) / perimeter_at_depth(depth);
}

/**
 * @brief Calculate the angle within a circle associated with a depth of flow
 */
static angle_type theta_at_depth(const length_type diameter, const length_type depth)
{
  return 2.0 * bu::acos(1.0 - 2.0 * depth / diameter);
}

// Circular cross section geometry
area_type circle_xsection::area_at_depth(const length_type depth)
{
  const angle_type theta = theta_at_depth(_diameter, depth);
  return bu::pow<2>(_diameter) / 8.0 * (theta.value() - bu::sin(theta));
}

length_type circle_xsection::perimeter_at_depth(const length_type depth)
{
  return theta_at_depth(_diameter, depth).value() * _diameter / 2.0;
}

length_type circle_xsection::top_width_at_depth(const length_type depth)
{
  return 2.0 * bu::sqrt(depth * (_diameter - depth));
}

length_type circle_xsection::hradius_at_depth(const length_type depth)
{
  const angle_type theta = theta_at_depth(_diameter, depth);
  return _diameter / 16.0 * (1.0 - bu::sin(theta) / theta.value());
}

// Triangular cross section geometry
area_type trapezoid_xsection::area_at_depth(const length_type depth)
{
  return _bottom_width * depth +
         (_slope_left + _slope_right) / 2.0 * bu::pow<2>(depth);
}

length_type trapezoid_xsection::perimeter_at_depth(const length_type depth)
{
  return _bottom_width + depth * (bu::sqrt(1.0 + bu::pow<2>(_slope_left)) +
                                  bu::sqrt(1.0 + bu::pow<2>(_slope_right)));
}

length_type trapezoid_xsection::top_width_at_depth(const length_type depth)
{
  return _bottom_width + depth * (_slope_left + _slope_right);
}

}  // namespace reswmm
