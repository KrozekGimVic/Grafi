add_subdirectory(googletest)
include_directories(googletest/googletest/include)
set(TEST_FILES
    topological_sort_test.cpp
    bfs_test.cpp
    dfs_test.cpp
    mimimum_spanning_tree_test.cpp
    bellman_ford_test.cpp
    floyd_warshall_test.cpp
    strongly_connected_components_test.cpp
)
add_executable(tests ${TEST_FILES})
target_link_libraries(tests grafi gtest gtest_main)
