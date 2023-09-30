add_library(sig_cp "")

target_sources(sig_cp
        PRIVATE
        data_structures/Z.hpp
        range_queries/LazySegmentTree.hpp
        graphs_trees/DSU.hpp
        range_queries/SparseTable.hpp
        data_structures/BinaryTrie.hpp
        data_structures/ordered_mset.hpp
        functions/LIS.hpp
        functions/seive.hpp
        PUBLIC
        sig_cp.cpp
        )

target_include_directories(sig_cp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )
