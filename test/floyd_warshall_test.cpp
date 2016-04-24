#include "floyd_warshall.hpp"
#include "gtest/gtest.h"

TEST(FloydWarshall, Basic) {
    weighted_graf_t graph = {{{2, -1}},
                             {{0, 3}},
                             {{3, 1}, {1, 3}},
                             {{1, -2}}};
    std::vector<std::vector<double>> expected_result = {{ 0, -2, -1,  0},
                                                        { 3,  0,  2,  3},
                                                        { 2, -1,  0,  1},
                                                        { 1, -2,  0,  0}};
    EXPECT_EQ(expected_result, floyd_warshall(graph));
}
