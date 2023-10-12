cmake_minimum_required(VERSION 3.21)
project(CompetitiveProgramming_Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(sol sol.cpp)
add_executable(brute brute.cpp)
