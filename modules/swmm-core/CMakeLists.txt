
# define transitive properties that will be required by users of swmm-core (e.g. swmm-cli)
add_library(swmm-core-public-settings INTERFACE)
target_include_directories(swmm-core-public-settings INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

# define properties that are needed to build this library, for use in subdirectories
# (rather than passing down variables)
add_library(swmm-core-settings INTERFACE)

# all the public properties will also be required for this library, so copy from public
target_link_libraries(swmm-core-settings INTERFACE swmm-core-public-settings)

# all includes should be relative to the src directory
target_include_directories(swmm-core-settings INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src)

# use -std=c++11 when compiling
target_compile_features(swmm-core-settings INTERFACE cxx_std_11)

# use position independent code
set_target_properties(swmm-core-settings PROPERTIES
  INTERFACE_POSITION_INDEPENDENT_CODE TRUE
)

# add the internal util library
add_subdirectory(./src/swmm/util)

# define the swmm-core library
add_library(swmm-core ./src/swmm/swmm.cc)
target_link_libraries(swmm-core PUBLIC swmm-core-public-settings)
target_link_libraries(swmm-core PRIVATE swmm-core-settings)

# link to the internal util library (see 'add_subdirectory' above)
target_link_libraries(swmm-core PRIVATE swmm-core-util)
