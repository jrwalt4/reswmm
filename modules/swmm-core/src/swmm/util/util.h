#ifndef SWMM_UTIL_H
#define SWMM_UTIL_H

namespace swmm
{
namespace util
{
typedef double (*root_fn_t)(double x);

double find_root(root_fn_t fn, double low, double high);

}  // namespace util
}  // namespace swmm

#endif  // SWMM_UTIL_H