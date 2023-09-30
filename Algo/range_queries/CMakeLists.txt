add_library(range_queries STATIC)

target_sources(range_queries
        PRIVATE
        LazySegmentTree.hpp
        SparseTable.hpp
        Fenwick.hpp
        PUBLIC
        range_queries.cpp
        )

target_include_directories(range_queries
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )
