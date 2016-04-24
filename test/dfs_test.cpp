#include "dfs.hpp"

#include "gtest/gtest.h"

TEST (CountComponentsDfs, Connected) {
	graf_t g = {{1, 2}, {0, 3}, {0, 1}, {1, 2}};
	EXPECT_EQ (1, count_components_dfs(g));

	g = {{1}, {2}, {3}, {4}, {1}};
	EXPECT_EQ (1, count_components_dfs(g));

	g = {{1}, {0}};
	EXPECT_EQ (1, count_components_dfs(g));

	g = {{1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {0, 1, 2}};
	EXPECT_EQ (1, count_components_dfs(g));
}
TEST (CountComponentsDfs, Disconnected) {
	graf_t g = {{1, 2}, {0, 2}, {0, 1}, {4}, {3}};
	EXPECT_EQ (2, count_components_dfs(g));

	g = {{0}, {1}, {2}, {3}, {4}};
	EXPECT_EQ (5, count_components_dfs(g));

	g = {{1}, {0}, {3}, {2}, {5}, {4}};
	EXPECT_EQ (3, count_components_dfs(g));
}
TEST (CountComponentsDfs, EmptyGraph) {
	graf_t g = {};
	EXPECT_EQ (0, count_components_dfs(g));
}
TEST (CountComponentsDfs, NoEdges) {
	graf_t g = {{}};
	EXPECT_EQ (1, count_components_dfs(g));

	g = {{}, {}, {}, {}};
	EXPECT_EQ (4, count_components_dfs(g));
}
