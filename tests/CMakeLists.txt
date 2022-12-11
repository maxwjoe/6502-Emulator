cmake_minimum_required(VERSION 3.10.2)

project(tests)

add_executable(test_CPU6502 test_CPU6502.cpp)
set(CMAKE_CXX_STANDARD 11)

target_link_libraries(test_CPU6502 PUBLIC
gtest
gtest_main
)