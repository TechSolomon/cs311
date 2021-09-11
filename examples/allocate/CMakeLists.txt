cmake_minimum_required(VERSION 3.20)
project(allocate)

set(CMAKE_CXX_STANDARD 20)

add_executable(allocate allocate2_raii.cpp)
