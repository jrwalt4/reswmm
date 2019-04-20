
set(SWMM_CORE_UTIL_SOURCES ./util.cc)
add_library(reswmm-core-util OBJECT ${SWMM_CORE_UTIL_SOURCES})
target_link_libraries(reswmm-core-util PUBLIC reswmm-core-settings)

find_package(Boost REQUIRED)

# target the header-only Boost libraries (needed for boost_math)
target_link_libraries(reswmm-core-util PRIVATE Boost::boost)
