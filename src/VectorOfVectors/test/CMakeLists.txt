
enable_testing()

add_executable(${BUILDTARGET}_test
    ${CMAKE_SOURCE_DIR}/src/${BUILDTARGET}/test/main.cpp  
)

target_link_libraries(${BUILDTARGET}_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${BUILDTARGET}_test)