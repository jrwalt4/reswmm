
# define transitive properties that will be required by users of reswmm-core (e.g. reswmm-cli)
add_library(reswmm-core-public-settings INTERFACE)
target_include_directories(reswmm-core-public-settings INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# define properties that are needed to build this library, for use in subdirectories
# (rather than passing down variables)
add_library(reswmm-core-settings INTERFACE)

# all the public properties will also be required for this library, so copy from public
target_link_libraries(reswmm-core-settings INTERFACE reswmm-core-public-settings)

# all includes should be relative to the src directory
target_include_directories(reswmm-core-settings INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# use -std=c++11 when compiling
target_compile_features(reswmm-core-settings INTERFACE cxx_std_11)

# use position independent code
set_target_properties(reswmm-core-settings PROPERTIES
  INTERFACE_POSITION_INDEPENDENT_CODE TRUE
)

# add the internal util library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/reswmm/util)

# define the swmm-core library
add_library(reswmm-core ${CMAKE_CURRENT_SOURCE_DIR}/src/reswmm/reswmm.cc)
target_link_libraries(reswmm-core PUBLIC reswmm-core-public-settings)
target_link_libraries(reswmm-core PRIVATE reswmm-core-settings)

# link to the internal util library (see 'add_subdirectory' above)
target_link_libraries(reswmm-core PRIVATE reswmm-core-util)
