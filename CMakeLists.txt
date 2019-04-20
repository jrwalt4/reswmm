# minimum version to use target_link_libraries() on an OBJECT library
cmake_minimum_required(VERSION 3.12)

project(reswmm VERSION 6.0.0)

# enable testing from root PROJECT_BINARY_DIR
enable_testing()

# add modules
add_subdirectory(./modules/reswmm-core)
add_subdirectory(./modules/reswmm-cli)
