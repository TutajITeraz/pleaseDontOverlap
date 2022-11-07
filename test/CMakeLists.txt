#include_directories("../deps/imgui/")
#include_directories("/deps/imgui/")

include_directories("deps/imgui/")

add_executable (LabelFilterTest LabelFilterTest.cpp)
target_link_libraries(LabelFilterTest imgui)

target_include_directories (LabelFilterTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
