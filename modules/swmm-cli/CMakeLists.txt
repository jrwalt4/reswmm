
# define the SWMM command line interface (CLI)
add_executable(swmm-cli ./src/swmm-cli.cc)

# link to the swmm-core library
target_link_libraries(swmm-cli PUBLIC swmm-core)

# for debugging, create a custom target to execute the CLI with no arguments
add_custom_target(run-swmm swmm-cli)
