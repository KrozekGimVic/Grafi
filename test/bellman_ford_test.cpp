#include "bellman_ford.hpp"

#include "gtest/gtest.h"
#include <vector>

TEST(BellmanFord, UniqueResult) {
    weighted_graf_t graph = {{std::pair<int,int>(1, 2), std::pair<int,int>(2,1)},
                            {std::pair<int,int>(3,1)}, {std::pair<int,int>(3,1), std::pair<int,int>(4,4)},
                            {std::pair<int,int>(5,9), std::pair<int,int>(4,-1)},
                            {std::pair<int,int>(6,3)}, {std::pair<int,int>(6,1)}, {}};
    std::vector<int> expectedResult = {0, 2, 1, 2, 1, 11, 4};

    EXPECT_EQ(expectedResult, bellman_ford(graph,0));

    //graph = {{1}, {3}, {3, 4}, {4}, {}};
    //expectedResult = {2, 0, 1, 3, 4};
    //EXPECT_EQ(expectedResult, topological_sort_dfs(graph));
}

