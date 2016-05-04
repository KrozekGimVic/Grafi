#include "topological_sort.hpp"

#include <vector>

#include "gtest/gtest.h"

using std::vector;

TEST(TopologicalSortDfs, UniqueResult) {
    graf_t graph = {{1, 2}, {3, 4}, {1, 3, 4}, {}, {}};
    vector<int> expectedResult = {0, 2, 1, 4, 3};

    EXPECT_EQ(expectedResult, topological_sort_dfs(graph));

    graph = {{1}, {3}, {3, 4}, {4}, {}};
    expectedResult = {2, 0, 1, 3, 4};
    EXPECT_EQ(expectedResult, topological_sort_dfs(graph));
}

TEST(TopologicalSortDfs, CyclicGraph) {
    graf_t graph = {{1, 3}, {2}, {3, 4}, {5, 6}, {1}, {}, {}};
    vector<int> expetedResult = {};

    EXPECT_EQ(expetedResult, topological_sort_dfs(graph));

    graph = {{1}, {2}, {3}, {4}, {0}};
    expetedResult = {};

    EXPECT_EQ(expetedResult, topological_sort_dfs(graph));
}

TEST(topological_sort_bfs, UniqueResult) {
    graf_t g = {{1}, {2}, {3}, {}};
    vector<int> expetedResult = {0, 1, 2, 3};

    EXPECT_EQ(expetedResult, topological_sort_bfs(g));
}

// TEST(topological_sort_bfs, UniqueResult2){
//     graf_t g = {{1,2,3}, {4}, {4,5,6}, {6}, {8,10}, {8,9}, {7}, {}, {9,10}, {}, {}};
//     vector<int> expetedResult = {0,1,2,3,4,5,6,8,9,7,10};

//     EXPECT_EQ(expetedResult, topological_sort_bfs(g));
// }

TEST(topological_sort_bfs, CyclicGraph) {
    graf_t g = {{1, 3}, {2}, {3, 4}, {5, 6}, {1}, {}, {}};
    vector<int> expetedResult = {};

    EXPECT_EQ(expetedResult, topological_sort_bfs(g));

    g = {{1}, {2}, {3}, {4}, {0}};
    expetedResult = {};

    EXPECT_EQ(expetedResult, topological_sort_bfs(g));
}
