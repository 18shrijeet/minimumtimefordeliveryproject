cmake_minimum_required(VERSION 3.10)
project(TestDeliveryApp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Google Test includes and libraries
set(GTEST_INCLUDES /opt/homebrew/opt/googletest/include ../)
set(GTEST_LIBS -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main -pthread)

# Source files
set(TEST_SOURCES test.cpp)

# Executable
add_executable(test ${TEST_SOURCES})

# Include directories
target_include_directories(test PUBLIC ${GTEST_INCLUDES})

# Link libraries
target_link_libraries(test ${GTEST_LIBS})

# This is to suppress warnings about unused variables
set_property(TARGET test PROPERTY CXX_STANDARD 14)
