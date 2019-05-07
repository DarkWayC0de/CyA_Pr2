cmake_minimum_required(VERSION 3.10)
project(Pr2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Pr2 main.cpp greedy_t.cpp greedy_t.hpp point_t.cpp point_t.hpp sky_t.cpp sky_t.hpp)