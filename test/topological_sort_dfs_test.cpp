#include "topological_sort_dfs.hpp"
#include <vector>
#include "gtest/gtest.h"

TEST(TopologicalSortDfs, UniqueResult) {
    graf_t graph = {{1, 2}, {3, 4}, {1, 3, 4}, {}, {}};
    std::vector<int> expectedResult = {0, 2, 1, 4, 3};

    EXPECT_EQ(expectedResult, topological_sort_dfs(graph));

    graph = {{1}, {3}, {3, 4}, {4}, {}};
    expectedResult = {2, 0, 1, 3, 4};
    EXPECT_EQ(expectedResult, topological_sort_dfs(graph));
}

TEST(TopologicalSortDfs, CyclicGraph) {
    graf_t graph = {{1, 3}, {2}, {3, 4}, {5, 6}, {1}, {}, {}};
    std::vector<int> expetedResult = {};

    EXPECT_EQ(expetedResult, topological_sort_dfs(graph));

    graph = {{1}, {2}, {3}, {4}, {0}};
    expetedResult = {};

    EXPECT_EQ(expetedResult, topological_sort_dfs(graph));
}
