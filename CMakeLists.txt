project(SurfaceCutCurve)

set(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.16)
find_package(PkgConfig)


pkg_check_modules(GTKMM gtkmm-3.0) # look into FindPkgConfig.cmake,
# it contains documentation
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES
# contain what you expect

add_subdirectory(src)
