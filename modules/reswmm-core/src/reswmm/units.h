/**
 * @file units.h
 * @brief Unit system used by reswmm
 *
 */
#ifndef RESWMM_UNITS_H
#define RESWMM_UNITS_H

#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/area.hpp>
#include <boost/units/systems/si/dimensionless.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/volume.hpp>

namespace reswmm
{
namespace units
{
// dimensionless unit
typedef boost::units::si::dimensionless dimensionless_unit;
typedef boost::units::quantity<dimensionless_unit, double> dimensionless_q;

typedef boost::units::si::plane_angle angle_unit;
BOOST_UNITS_STATIC_CONSTANT(radians, angle_unit);
typedef boost::units::quantity<angle_unit, double> angle_q;

// length unit
typedef boost::units::si::length length_unit;
BOOST_UNITS_STATIC_CONSTANT(meters, length_unit);
typedef boost::units::quantity<length_unit, double> length_q;

// area unit
typedef boost::units::si::area area_unit;
BOOST_UNITS_STATIC_CONSTANT(square_meters, area_unit);
typedef boost::units::quantity<area_unit, double> area_q;

// volume unit
typedef boost::units::si::volume volume_unit;
BOOST_UNITS_STATIC_CONSTANT(cubic_meters, volume_unit);
typedef boost::units::quantity<volume_unit, double> volume_q;

// time unit
typedef boost::units::si::time time_unit;
BOOST_UNITS_STATIC_CONSTANT(seconds, time_unit);
typedef boost::units::quantity<time_unit, double> time_q;

// flow unit
typedef boost::units::derived_dimension<boost::units::length_base_dimension, 3,
                                        boost::units::time_base_dimension,
                                        -1>::type flow_dimension;
typedef boost::units::unit<flow_dimension, boost::units::si::system> flow_unit;
BOOST_UNITS_STATIC_CONSTANT(cubic_meters_second, flow_unit);
BOOST_UNITS_STATIC_CONSTANT(cms, flow_unit);
typedef boost::units::quantity<flow_unit, double> flow_q;
}  // namespace units

}  // namespace reswmm

inline reswmm::units::dimensionless_q operator+(double lhs, reswmm::units::dimensionless_q rhs) {
  return reswmm::units::dimensionless_q::from_value(lhs) + rhs;
}

inline reswmm::units::dimensionless_q operator+(reswmm::units::dimensionless_q lhs, double rhs) {
  return lhs + reswmm::units::dimensionless_q::from_value(rhs);
}

inline reswmm::units::dimensionless_q operator-(double lhs, reswmm::units::dimensionless_q rhs) {
  return reswmm::units::dimensionless_q::from_value(lhs) - rhs;
}

inline reswmm::units::dimensionless_q operator-(reswmm::units::dimensionless_q lhs, double rhs) {
  return lhs - reswmm::units::dimensionless_q::from_value(rhs);
}

#endif  // RESWMM_UNITS_H
