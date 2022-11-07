cmake_minimum_required (VERSION 3.3)
project (pleaseDontOverlap)

include_directories(deps/)
include_directories(deps/imgui)

add_subdirectory (src)
add_subdirectory (test)