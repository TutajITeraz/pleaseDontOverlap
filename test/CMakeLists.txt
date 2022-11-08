
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable (LabelFilterTest LabelFilterTest.cpp)

target_link_libraries( LabelFilterTest ${OpenCV_LIBS} LabelFilter )
target_link_libraries( LabelFilterTest LabelFilter )

target_include_directories (LabelFilterTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
