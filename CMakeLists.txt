cmake_minimum_required(VERSION 3.21)
project(CompetitiveProgramming)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Algo)
add_subdirectory(Templates)

add_executable(temp Misc/temp.cpp)
add_compile_options(temp
        -Wall -Wextra
        -fsanitize=address)
