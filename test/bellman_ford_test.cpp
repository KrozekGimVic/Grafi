#include "bellman_ford.hpp"

#include "gtest/gtest.h"
#include <vector>

TEST(BellmanFord, UniqueResult) {
    weighted_graf_t graph = {{{1, 2}, {2, 1}}, {{3, 1}}, {{3, 1}, {4, 4}},
                             {{5, 9}, {4, -1}}, {{6, 3}}, {{6, 1}}, {}};
    std::vector<double> expectedResult = {0, 2, 1, 2, 1, 11, 4};

    EXPECT_EQ(expectedResult, bellman_ford(graph, 0));

    // graph = {{1}, {3}, {3, 4}, {4}, {}};
    // expectedResult = {2, 0, 1, 3, 4};
    // EXPECT_EQ(expectedResult, topological_sort_dfs(graph));
}
