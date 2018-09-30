#include "swmm/swmm.h"

#include "swmm/util/util.h"

namespace swmm
{
static const double SQRT_SEEK = 2;

double sqr_root(double x)
{
  // test routine to estimate sqrt(SQRT_SEEK)
  return x * x - SQRT_SEEK;
}
double run() { return util::find_root(sqr_root, 1.0, 2.0); }

}  // namespace swmm
