/**
 * reSWMM core library header
 * @file reswmm.h
 */

#ifndef RESWMM_SWMM_H
#define RESWMM_SWMM_H

/**
 * core namespace
 */
namespace reswmm
{

/**
 * @brief Run the reswmm model
 * 
 * After all the inputs have been parsed, this runs
 * and generates the output files for use by the end user
 *  
 * @return The result of the reswmm model run
 */
double run();

}  // namespace reswmm

#endif  // RESWMM_SWMM_H
