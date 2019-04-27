/**
 * @file xsection.h
 * @brief Conduit cross section definitions
 *
 */
#ifndef RESWMM_XSECTION_H
#define RESWMM_XSECTION_H

namespace reswmm
{
/**
 * @brief Abstract base cross section class
 */
struct xsection
{
  /**
   * @brief Flow area at a given depth of flow
   */
  virtual double area_at_depth(const double depth) = 0;

  /**
   * @brief Wetted perimeter at a given depth of flow
   */
  virtual double perimeter_at_depth(const double depth) = 0;

  /**
   * @brief Top width at a given depth of flow
   */
  virtual double top_width_at_depth(const double depth) = 0;

  /**
   * @brief Hydraulic radius at a given depth of flow
   */
  virtual double hradius_at_depth(const double depth);
};

/**
 * @brief Circular cross section
 *
 */
class circle_xsection : public xsection
{
 private:
  double _diameter;

 public:
  /**
   * @brief Construct a circle with a given diameter
   */
  circle_xsection(const double diameter = 0) : _diameter(diameter){};
  virtual double area_at_depth(const double depth) override;
  virtual double perimeter_at_depth(const double depth) override;
  virtual double top_width_at_depth(const double depth) override;
  virtual double hradius_at_depth(const double depth) override;
};

/**
 * @brief Triangular cross section
 */
class trapezoid_xsection : public xsection
{
 private:
  double _bottom_width;
  double _slope_right;
  double _slope_left;

 public:
  /**
   * @brief Construct a trapezoid with given bottom width, right side slope, and
   * left side slope
   */
  trapezoid_xsection(const double bw = 0, const double ssr = 0, const double ssl = 0) :
      _bottom_width(bw),
      _slope_right(ssr),
      _slope_left(ssl)
  {}
  virtual double area_at_depth(const double depth) override;
  virtual double perimeter_at_depth(const double depth) override;
  virtual double top_width_at_depth(const double depth) override;
  virtual double hradius_at_depth(const double depth) override;
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
  rectangle_xsection(const double bw = 0) : trapezoid_xsection(bw) {}
};

}  // namespace reswmm
#endif  // RESWMM_XSECTION_H
