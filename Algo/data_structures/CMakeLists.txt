add_library(data_structures STATIC)

target_sources(data_structures
        PRIVATE
        Z.hpp
        BinaryTrie.hpp
        ordered_mset.hpp
        PUBLIC
        data_structures.cpp
        )

target_include_directories(data_structures
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )
