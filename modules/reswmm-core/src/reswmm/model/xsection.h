/**
 * @file xsection.h
 * @brief Conduit cross section definitions
 *
 */
#ifndef RESWMM_XSECTION_H
#define RESWMM_XSECTION_H

#include "reswmm/units.h"

namespace reswmm
{
/**
 * @brief Abstract base cross section class
 */
struct xsection
{
  typedef units::length_q length_type;
  typedef units::area_q area_type;
  typedef units::dimensionless_q dimensionless_type;
  /**
   * @brief Flow area at a given depth of flow
   */
  virtual area_type area_at_depth(const length_type depth) = 0;

  /**
   * @brief Wetted perimeter at a given depth of flow
   */
  virtual length_type perimeter_at_depth(const length_type depth) = 0;

  /**
   * @brief Top width at a given depth of flow
   */
  virtual length_type top_width_at_depth(const length_type depth) = 0;

  /**
   * @brief Hydraulic radius at a given depth of flow
   */
  virtual length_type hradius_at_depth(const length_type depth);
};

/**
 * @brief Circular cross section
 *
 */
class circle_xsection : public xsection
{
 private:
  length_type _diameter;

 public:
  /**
   * @brief Construct a circle with a given diameter
   */
  circle_xsection(const length_type diameter = 0) : _diameter(diameter){};
  virtual units::area_q area_at_depth(const length_type depth) override;
  virtual length_type perimeter_at_depth(const length_type depth) override;
  virtual length_type top_width_at_depth(const length_type depth) override;
  virtual length_type hradius_at_depth(const length_type depth) override;
};

/**
 * @brief Triangular cross section
 */
class trapezoid_xsection : public xsection
{
 private:
  length_type _bottom_width;
  dimensionless_type _slope_right;
  dimensionless_type _slope_left;

 public:
  /**
   * @brief Construct a trapezoid with given bottom width, right side slope, and
   * left side slope
   */
  trapezoid_xsection(const length_type bw = 0, const dimensionless_type ssr = 0, const dimensionless_type ssl = 0) :
      _bottom_width(bw),
      _slope_right(ssr),
      _slope_left(ssl)
  {}
  virtual area_type area_at_depth(const length_type depth) override;
  virtual length_type perimeter_at_depth(const length_type depth) override;
  virtual length_type top_width_at_depth(const length_type depth) override;
};

/**
 * @brief Rectangular cross section
 */
class rectangle_xsection : public trapezoid_xsection
{
 public:
  /**
   * @brief Construct a rectangle with given bottom width
   */
  rectangle_xsection(const length_type bw = 0) : trapezoid_xsection(bw) {}
};

}  // namespace reswmm
#endif  // RESWMM_XSECTION_H
