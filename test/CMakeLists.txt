add_subdirectory(googletest)
include_directories(googletest/googletest/include)
set(TEST_FILES
    topological_sort_dfs_test.cpp
    topological_sort_bfs_test.cpp
    bfs_test.cpp
    dfs_test.cpp
    mimimum_spanning_tree_kruskal_test.cpp
)
add_executable(tests ${TEST_FILES})
target_link_libraries(tests grafi gtest gtest_main)
