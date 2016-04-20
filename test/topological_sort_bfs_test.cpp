#include "topological_sort_bfs.hpp"

#include "gtest/gtest.h"

using std::vector;

TEST(topological_sort_bfs, UniqueResult){
   graf_t g = {{1},{2},{3}, {}};
   vector<int> expetedResult = {0,1,2,3};

   EXPECT_EQ(expetedResult, topological_sort_bfs(g));
}
