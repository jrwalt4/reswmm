#ifndef RESWMM_UTIL_H
#define RESWMM_UTIL_H

namespace reswmm
{
namespace util
{
typedef double (*root_fn_t)(double x);

double find_root(root_fn_t fn, double low, double high);

}  // namespace util
}  // namespace reswmm

#endif  // RESWMM_UTIL_H