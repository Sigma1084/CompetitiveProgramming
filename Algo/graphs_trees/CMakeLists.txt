add_library(graphs_trees STATIC "")

target_link_libraries(graphs_trees
        PUBLIC
        range_queries
        )

target_sources(graphs_trees
        PRIVATE
        Tree.hpp
        LCATree.hpp
        PUBLIC
        graphs_trees.cpp
        )

target_include_directories(graphs_trees
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )
