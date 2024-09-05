cmake_minimum_required(VERSION 3.17)
project("CompetitiveProgramming_Snippets")
set(CMAKE_CXX_STANDARD 20)

add_library(sig_cp "")

target_sources(sig_cp
        PRIVATE
        number_theory/Z.hpp
        range_queries/Fenwick.hpp
        range_queries/SparseTable.hpp
        range_queries/SegmentTree.hpp
        range_queries/LazySegmentTree.hpp
        data_structures/BinaryTrie.hpp
        data_structures/ordered_mset.hpp
        functions/LIS.hpp
        number_theory/sieve.hpp
        number_theory/modular.hpp
        number_theory/combinatorics.hpp
        graphs_trees/DSU.hpp
        graphs_trees/Tree.hpp
        graphs_trees/LCATree.hpp
        strings/zFunction.hpp
        PUBLIC
        sig_cp.cpp
        )

target_include_directories(sig_cp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )
