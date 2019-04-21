/**
 * Core reSWMM utilities
 * @file util.h
 */

#ifndef RESWMM_UTIL_H
#define RESWMM_UTIL_H

namespace reswmm
{
/**
 * core util namespace
 */
namespace util
{
/**
 * Unary root finding function
 */
typedef double (*root_fn_t)(double x);

/**
 * @brief Find the root of a unary function
 * 
 * @param fn unary function
 * @param low lower bound
 * @param high upper bound
 * @return the input value where `fn=0`
 */
double find_root(root_fn_t fn, double low, double high);

}  // namespace util
}  // namespace reswmm

#endif  // RESWMM_UTIL_H