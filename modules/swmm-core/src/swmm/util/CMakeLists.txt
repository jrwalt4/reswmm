
set(SWMM_CORE_UTIL_SOURCES ./util.cc)
add_library(swmm-core-util OBJECT ${SWMM_CORE_UTIL_SOURCES})
target_link_libraries(swmm-core-util PUBLIC swmm-core-settings)

find_package(Boost REQUIRED)

# target the header-only Boost libraries (needed for boost_math)
target_link_libraries(swmm-core-util PRIVATE Boost::boost)
