##
# Tests configuration based on Google Test framework

cmake_minimum_required(VERSION 3.16)

# Enable support for Google Test framework
find_package(GTest)

# Test project name
project(case1_test)

# Add googletest subdirectory
add_subdirectory(/usr/src/googletest ./googletest)

# Create test executable
add_executable(${PROJECT_NAME}
    test.cpp)

# Link required libraries
target_link_libraries(${PROJECT_NAME} case1 gtest gtest_main)

# Add tests to CTest
gtest_discover_tests(${PROJECT_NAME})