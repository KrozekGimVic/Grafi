add_subdirectory(googletest)
include_directories(googletest/googletest/include)
<<<<<<< HEAD
set(TEST_FILES topological_sort_dfs_test.cpp topological_sort_bfs_test.cpp bfs_test.cpp)
=======
set(TEST_FILES dfs_topological_sort_test.cpp bfs_test.cpp)
>>>>>>> 9c5ca41108ce6ccb02a54922b4a6de6b06148219
add_executable(tests ${TEST_FILES})
target_link_libraries(tests grafi gtest gtest_main)
