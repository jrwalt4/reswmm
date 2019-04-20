
# define the SWMM command line interface (CLI)
add_executable(reswmm-cli ${CMAKE_CURRENT_SOURCE_DIR}/src/reswmm-cli.cc)

# link to the swmm-core library
target_link_libraries(reswmm-cli PUBLIC reswmm-core)

# for debugging, create a custom target to execute the CLI with no arguments
add_custom_target(run-cli reswmm-cli)
