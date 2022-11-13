add_executable (ConsoleTester 
                    ConsoleTester.cpp
                    CommonTestFunctions.cpp
    )
target_link_libraries( ConsoleTester LabelFilter )


target_include_directories (ConsoleTester PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


if (WITH_VISUAL_TESTS)

    find_package( OpenCV REQUIRED )
    include_directories( ${OpenCV_INCLUDE_DIRS} )

    add_executable (VisualTester 
                        VisualTester.cpp
                        CommonTestFunctions.cpp
        )

    target_link_libraries( VisualTester ${OpenCV_LIBS} LabelFilter )

    target_include_directories (VisualTester PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

endif ()