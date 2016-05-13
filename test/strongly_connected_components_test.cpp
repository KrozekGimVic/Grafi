#include "strongly_connected_components.hpp"

#include <algorithm>
#include <vector>
#include "utils.hpp"
#include "gtest/gtest.h"

bool compare_func(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() == b.size()) return a[0] < b[0];
    return a.size() < b.size();
}

std::vector<std::vector<int>> get_result(weighted_graf_t g) {
    std::vector<std::vector<int>> v = strongly_connected_components(g);
    for (auto& i : v) std::sort(i.begin(), i.end());
    std::sort(v.begin(), v.end(), compare_func);
    return v;
}

TEST(StronglyConnectedComponents, Components) {
    weighted_graf_t g = {{{1, 0.5}}, {{0, 0.5}}, {{3, 0.5}}, {{2, 0.5}}};
    std::vector<std::vector<int>> v = {{0, 1}, {2, 3}};
    EXPECT_EQ(v, get_result(g));
    g = {{{1, 0.5}}, {{0, 0.5}}, {{2, 0.5}}};
    v = {{2}, {0, 1}};
    EXPECT_EQ(v, get_result(g));
    g = {{{3, 1}}, {{2, 1}}, {{1, 1}}, {{0, 1}}};
    v = {{0, 3}, {1, 2}};
    EXPECT_EQ(v, get_result(g));
    g = {{{0, 1}}, {{1, 1}}, {{2, 1}}, {{3, 1}}};
    v = {{0}, {1}, {2}, {3}};
    EXPECT_EQ(v, get_result(g));
    g = {};
    v = {};
    EXPECT_EQ(v, get_result(g));
    g = {{}};
    v = {{0}};
    EXPECT_EQ(v, get_result(g));
    g = {{}, {}, {}};
    v = {{0}, {1}, {2}};
    EXPECT_EQ(v, get_result(g));
    g = {{{1, 1}}, {{2, 1}}, {{0, 1}}, {}};
    v = {{3}, {0, 1, 2}};
    EXPECT_EQ(v, get_result(g));
    g = {{{6, 1}}, {{0, 1}}, {{1, 1}}, {{2, 1}}, {{3, 1}}, {{4, 1}}, {{5, 1}}};
    v = {{0, 1, 2, 3, 4, 5, 6}};
    EXPECT_EQ(v, get_result(g));
    g = {{{6, 1}}, {{0, 1}}, {{2, 1}}, {{4, 1}}, {{3, 1}}, {{4, 1}}, {{1, 1}}};
    v = {{2}, {5}, {3, 4}, {0, 1, 6}};
    EXPECT_EQ(v, get_result(g));
    g = {{{3, 0.5}}, {{2, 0.4}}, {{1, 0.3}}, {}};
    v = {{0}, {3}, {1, 2}};
    EXPECT_EQ(v, get_result(g));
    g = {{}, {{0, 0}}, {{0, 0}, {1, 0}}, {{0, 0}, {1, 0}, {2, 0}}};
    v = {{0}, {1}, {2}, {3}};
    EXPECT_EQ(v, get_result(g));
}
