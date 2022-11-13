cmake_minimum_required (VERSION 3.3)
project (pleaseDontOverlap)

option (WITH_VISUAL_TESTS "enable building visual test executable" OFF)

include_directories(deps/)
include_directories(deps/imgui)

add_subdirectory (src)
add_subdirectory (test)