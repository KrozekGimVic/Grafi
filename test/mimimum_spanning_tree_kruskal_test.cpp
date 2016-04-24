#include <limits>
#include "minimum_spanning_tree_kruskal.hpp"
#include "utils.hpp"
#include "gtest/gtest.h"

TEST(MinimumSpanningTreeKruskal, Basic) {
    weighted_graf_t g = { {{1, 1}, {2, 2}}, {{2, 2}}, {} };
    EXPECT_EQ(3, sum_of_paths_minimum_spanning_tree(g));
    g = { {{1, 1}, {2, 1}, {3, 1}, {4, 1}}, {}, {}, {}, {}};
    EXPECT_EQ(4, sum_of_paths_minimum_spanning_tree(g));
    g = {{{1, 1}}, {{2, 2}}, {{3, 3}}, {{4, 4}}, {}};
    EXPECT_EQ(10, sum_of_paths_minimum_spanning_tree(g));
    g = {{{1, 10}, {2, 1}, {3, 10}}, {{3, 1}}, {{1, 1}}, {}};
    EXPECT_EQ(3, sum_of_paths_minimum_spanning_tree(g));
    g = {{{1, 1}, {2, 1}, {3, 1}}, {{2, 1}, {3, 1}}, {{3, 1}}, {}};
    EXPECT_EQ(3, sum_of_paths_minimum_spanning_tree(g));
    g = {{{1, 2}}, {{0, 1}}};
    EXPECT_EQ(1, sum_of_paths_minimum_spanning_tree(g));
    g = {{{1, 1}}, {{0, 2}}};
    EXPECT_EQ(1, sum_of_paths_minimum_spanning_tree(g));
    g = {{{1, -1}}, {{0, 0}}};
    EXPECT_EQ(-1, sum_of_paths_minimum_spanning_tree(g));
    g = {{{1, 1}}, {{0, -1}}, {{0, -2}, {1, -3}}};
    EXPECT_EQ(-5, sum_of_paths_minimum_spanning_tree(g));
}

TEST(MinimumSpanningTreeKruskal, SpecialCases) {
    weighted_graf_t g = {{{1, 1}}, {}, {{3, 1}}, {}};  // Not connected
    EXPECT_EQ(std::numeric_limits<int>::max(), sum_of_paths_minimum_spanning_tree(g));
    g = {};  // No edges
    EXPECT_EQ(0, sum_of_paths_minimum_spanning_tree(g));
    g = {{{0, 1}}};  // Single node is connected to itself
    EXPECT_EQ(0, sum_of_paths_minimum_spanning_tree(g));
}
