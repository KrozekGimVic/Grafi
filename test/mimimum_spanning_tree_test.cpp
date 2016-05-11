#include <limits>
#include "minimum_spanning_tree.hpp"
#include "utils.hpp"
#include "gtest/gtest.h"

TEST(MinimumSpanningTreeKruskal, Basic) {
    weighted_graf_t g = {{{1, 1}, {2, 2}}, {{2, 2}}, {}};
    EXPECT_EQ(3, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{1, 1}, {2, 1}, {3, 1}, {4, 1}}, {}, {}, {}, {}};
    EXPECT_EQ(4, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{1, 1}}, {{2, 2}}, {{3, 3}}, {{4, 4}}, {}};
    EXPECT_EQ(10, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{1, 10}, {2, 1}, {3, 10}}, {{3, 1}}, {{1, 1}}, {}};
    EXPECT_EQ(3, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{1, 1}, {2, 1}, {3, 1}}, {{2, 1}, {3, 1}}, {{3, 1}}, {}};
    EXPECT_EQ(3, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{1, 2}, {1, 1}}, {}};
    EXPECT_EQ(1, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{1, 1},{1, 2}}, {}};
    EXPECT_EQ(1, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{1, -1}, {1, 0}}, {}};
    EXPECT_EQ(-1, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{1, -1}, {2, -2}}, {{0, -1}, {2, -3}}, {{0, -2}, {1, -3}}};
    EXPECT_EQ(-5, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{1, 0.1}, {2, 2.1}}, {{0, 0.1}, {2, 4}}, {{1, 4}, {0, 2.1}}};
    EXPECT_EQ(2.2, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{}, {{0, 1}}, {{0, 1}}};
    EXPECT_EQ(2, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{}, {{0, 1.5}, {2, 1}, {3, 1.5}}, {{0, 2.5}, {3, 1.5}}, {{0, 0.5}}, {{0, 0.5}}};
    EXPECT_EQ(3.5, sum_of_paths_minimum_spanning_tree_kruskal(g));
}

TEST(MinimumSpanningTreeKruskal, SpecialCases) {
    weighted_graf_t g = {{{1, 1}}, {}, {{3, 1}}, {}};  // Not connected
    EXPECT_EQ(INFINITY, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {};  // No edges
    EXPECT_EQ(0, sum_of_paths_minimum_spanning_tree_kruskal(g));
    g = {{{0, 1}}};  // Single node is connected to itself
    EXPECT_EQ(0, sum_of_paths_minimum_spanning_tree_kruskal(g));
}

TEST(MinimumSpanningTreePrim, Basic) {
    weighted_graf_t g = {{{1, 1}, {2, 2}}, {{2, 2}}, {}};
    EXPECT_EQ(3, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{1, 1}, {2, 1}, {3, 1}, {4, 1}}, {}, {}, {}, {}};
    EXPECT_EQ(4, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{1, 1}}, {{2, 2}}, {{3, 3}}, {{4, 4}}, {}};
    EXPECT_EQ(10, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{1, 10}, {2, 1}, {3, 10}}, {{3, 1}}, {{1, 1}}, {}};
    EXPECT_EQ(3, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{1, 1}, {2, 1}, {3, 1}}, {{2, 1}, {3, 1}}, {{3, 1}}, {}};
    EXPECT_EQ(3, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{1, 2}, {1, 1}}, {}};
    EXPECT_EQ(1, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{1, 1},{1, 2}}, {}};
    EXPECT_EQ(1, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{1, -1}, {1, 0}}, {}};
    EXPECT_EQ(-1, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{1, -1}, {2, -2}}, {{0, -1}, {2, -3}}, {{0, -2}, {1, -3}}};
    EXPECT_EQ(-5, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{1, 0.1}, {2, 2.1}}, {{0, 0.1}, {2, 4}}, {{1, 4}, {0, 2.1}}};
    EXPECT_EQ(2.2, sum_of_paths_minimum_spanning_tree_prim(g));
    // g = {{}, {{0, 1}}, {{0, 1}}};
    // EXPECT_EQ(2, sum_of_paths_minimum_spanning_tree_prim(g));
    // g = {{}, {{0, 1.5}, {2, 1}, {3, 1.5}}, {{0, 2.5}, {3, 1.5}}, {{0, 0.5}}, {{0, 0.5}}};
    // EXPECT_EQ(3.5, sum_of_paths_minimum_spanning_tree_prim(g));
}

TEST(MinimumSpanningTreePrim, SpecialCases) {
    weighted_graf_t g = {{{1, 1}}, {{0, 1}}, {{3, 1}}, {{2, 1}}};  // Not connected
    EXPECT_EQ(INFINITY, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {};  // No edges
    EXPECT_EQ(0, sum_of_paths_minimum_spanning_tree_prim(g));
    g = {{{0, 1}}};  // Single node is connected to itself
    EXPECT_EQ(0, sum_of_paths_minimum_spanning_tree_prim(g));
}
