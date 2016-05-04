#include "topological_sort.hpp"

#include <vector>

#include "gtest/gtest.h"

using std::vector;

TEST(TopologicalSort, IsTopologicallySorted) {
    EXPECT_TRUE(is_topologically_sorted({0}, {{}}));

    EXPECT_TRUE(is_topologically_sorted({0, 1}, {{1}, {}}));
    EXPECT_FALSE(is_topologically_sorted({1, 0}, {{1}, {}}));

    EXPECT_TRUE(is_topologically_sorted({1, 0}, {{}, {0}}));
    EXPECT_FALSE(is_topologically_sorted({0, 1}, {{}, {0}}));

    EXPECT_TRUE(is_topologically_sorted({3, 2, 4, 0, 1}, {{}, {}, {0}, {2, 4}, {1, 0}}));
    EXPECT_TRUE(is_topologically_sorted({3, 2, 4, 1, 0}, {{}, {}, {0}, {2, 4}, {1, 0}}));
    EXPECT_TRUE(is_topologically_sorted({3, 4, 2, 0, 1}, {{}, {}, {0}, {2, 4}, {1, 0}}));
    EXPECT_TRUE(is_topologically_sorted({3, 4, 2, 1, 0}, {{}, {}, {0}, {2, 4}, {1, 0}}));
    EXPECT_TRUE(is_topologically_sorted({3, 4, 1, 2, 0}, {{}, {}, {0}, {2, 4}, {1, 0}}));

    EXPECT_FALSE(is_topologically_sorted({3, 2, 0, 4, 1}, {{}, {}, {0}, {2, 4}, {1, 0}}));
    EXPECT_FALSE(is_topologically_sorted({3, 4, 1, 0, 2}, {{}, {}, {0}, {2, 4}, {1, 0}}));
    EXPECT_FALSE(is_topologically_sorted({0, 1, 2, 3, 4}, {{}, {}, {0}, {2, 4}, {1, 0}}));

    EXPECT_TRUE(is_topologically_sorted({0, 1}, {{}, {}}));
    EXPECT_TRUE(is_topologically_sorted({1, 0}, {{}, {}}));
}

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

TEST(TopologicalSortBfs, UniqueResult) {
    EXPECT_EQ(vector<int>({0, 1}), topological_sort_bfs({{1}, {}}));
    EXPECT_EQ(vector<int>({1, 0}), topological_sort_bfs({{}, {0}}));

    graf_t g = {{1}, {2}, {3}, {}};
    vector<int> expetedResult = {0, 1, 2, 3};
    EXPECT_EQ(expetedResult, topological_sort_bfs(g));

    g = {{1}, {}, {0}, {2, 4}, {0, 1, 2}};
    expetedResult = {3, 4, 2, 0, 1};
    EXPECT_EQ(expetedResult, topological_sort_bfs(g));
}

TEST(TopologicalSortBfs, General) {
    graf_t g = {{1, 2, 3}, {4}, {4, 5, 6}, {6}, {8, 10}, {8, 9}, {7}, {}, {9, 10}, {}, {}};
    vector<int> result = topological_sort_bfs(g);
    ASSERT_EQ(g.size(), result.size());
    EXPECT_TRUE(is_topologically_sorted(result, g));

    g = {{}, {}, {}};
    result = topological_sort_bfs(g);
    ASSERT_EQ(g.size(), result.size());
    EXPECT_TRUE(is_topologically_sorted(result, g));

    g = {{}, {2}, {}, {1}};
    result = topological_sort_bfs(g);
    ASSERT_EQ(g.size(), result.size());
    EXPECT_TRUE(is_topologically_sorted(result, g));
}

TEST(TopologicalSortBfs, CyclicGraph) {
    graf_t g = {{1, 3}, {2}, {3, 4}, {5, 6}, {1}, {}, {}};
    vector<int> expetedResult = {};

    EXPECT_EQ(expetedResult, topological_sort_bfs(g));

    g = {{1}, {2}, {3}, {4}, {0}};
    expetedResult = {};

    EXPECT_EQ(expetedResult, topological_sort_bfs(g));
}

