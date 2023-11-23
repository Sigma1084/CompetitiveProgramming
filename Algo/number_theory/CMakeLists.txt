add_library(number_theory STATIC "")

target_sources(number_theory
        PRIVATE
        sieve.hpp
        combinatorics.hpp
        modular.hpp
        PUBLIC
        number_theory.cpp
        )

target_include_directories(number_theory
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )
