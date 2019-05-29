#include "reswmm/reswmm.h"

#include "reswmm/model/xsection.h"
#include "reswmm/units.h"
#include "reswmm/units_io.h"
#include "reswmm/util/util.h"
#include "reswmm/util/types.h"

#include <iostream>
#include <memory>

namespace reswmm
{
static const double SQRT_SEEK = 2;

/**
 * @brief Test routine to estimate `sqrt(SQRT_SEEK)`
 * 
 * @param x 
 * @return the error between x and the sought value 
 */
double sqr_root(double x)
{
  // test routine to estimate sqrt(SQRT_SEEK)
  return x * x - SQRT_SEEK;
}

double run()
{

  util::multiply<int, double>::result_type i;
  auto k = i * 2;

  auto val = util::power<units::length_q, 3>::result_type::from_value(3.0);
  std::cout << val << std::endl;

  auto c = std::make_shared<circle_xsection>(2.0 * units::meters);
  std::cout << c->area_at_depth(1.0 * units::meters) << std::endl;
  return util::find_root(sqr_root, 1.0, 2.0);
}

}  // namespace reswmm
