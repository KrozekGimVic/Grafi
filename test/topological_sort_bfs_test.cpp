#include "topological_sort_bfs.hpp"

#include "gtest/gtest.h"

using std::vector;

TEST(topological_sort_bfs, UniqueResult){
    graf_t g = {{1},{2},{3}, {}};
    vector<int> expetedResult = {1,2,3,4};

    EXPECT_EQ(expetedResult, topological_sort_bfs(g));
}