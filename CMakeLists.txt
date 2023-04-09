cmake_minimum_required(VERSION 3.14)

project(competitive-programming-template)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )

FetchContent_MakeAvailable(googletest)

add_executable(main test.cpp)
target_link_libraries(main gtest_main)
target_include_directories(main PUBLIC "include")
add_test(NAME test COMMAND main)
enable_testing()
