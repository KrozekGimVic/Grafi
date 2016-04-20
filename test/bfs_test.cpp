#include "gtest/gtest.h"
#include "typedefs.hpp"
#include "bfs.hpp"

TEST (CountComponentsBfs, Connected) {
    graf_t g = {{1, 2}, {0, 3}, {0, 1}, {1, 2}};
    EXPECT_EQ (1, count_components_bfs(g));

    g = {{1}, {2}, {3}, {4}, {1}};
    EXPECT_EQ (1, count_components_bfs(g));

    g = {{1}, {0}};
    EXPECT_EQ (1, count_components_bfs(g));

    g = {{1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {0, 1, 2}};
    EXPECT_EQ (1, count_components_bfs(g));
}
TEST (CountComponentsBfs, Disconnected) {
    graf_t g = {{1, 2}, {0, 2}, {0, 1}, {4}, {3}};
    EXPECT_EQ (2, count_components_bfs(g));

    g = {{0}, {1}, {2}, {3}, {4}};
    EXPECT_EQ (5, count_components_bfs(g));

    g = {{1}, {0}, {3}, {2}, {5}, {4}};
    EXPECT_EQ (3, count_components_bfs(g));
}
TEST (CountComponentsBfs, EmptyGraph) {
    graf_t g = {};
    EXPECT_EQ (0, count_components_bfs(g));
}
TEST (CountComponentsBfs, NoEdges) {
    graf_t g = {{}};
    EXPECT_EQ (1, count_components_bfs(g));

    g = {{}, {}, {}, {}};
    EXPECT_EQ (4, count_components_bfs(g));
}
