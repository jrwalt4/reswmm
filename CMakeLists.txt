# minimum version to use target_link_libraries() on an OBJECT library
cmake_minimum_required(VERSION 3.12)

project(reSWMM VERSION 0.0.0)

# enable testing from root PROJECT_BINARY_DIR
enable_testing()

# add modules
add_subdirectory(./modules/reswmm-core)
add_subdirectory(./modules/reswmm-cli)

# create documentation
set(BUILD_DOCS OFF CACHE BOOL "Build documentation with Doxygen (default OFF)")

if(BUILD_DOCS)
  find_package(Doxygen
    REQUIRED dot)
  
  if(DOXYGEN_FOUND)
    set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
    set(DOXYGEN_HTML_TIMESTAMP YES)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/docs)
    doxygen_add_docs(
      doxygen
      ${CMAKE_SOURCE_DIR}/modules
      ${CMAKE_SOURCE_DIR}/README.md
      COMMENT "Generate HTML"
    )
  endif(DOXYGEN_FOUND)

endif(BUILD_DOCS)
