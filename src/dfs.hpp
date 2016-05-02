#ifndef SRC_DFS_HPP_
#define SRC_DFS_HPP_

#include "utils.hpp"

#include <vector>

/**
 * @file dfs.hpp
 * @author Bor Brecelj <bor.brecelj@gmail.com>
 * @brief Depth first search.
 */

/**
 * @brief Depth first search on one component of a graph.
 * @param pos Position in a graph.
 * @param v Visited nodes.
 * @param graph A directed graph.
 */
void dfs(int pos, std::vector<bool>& v, const graf_t& graph);

/**
 * @brief Counts components of a graph using depth first search.
 * @param graph A directed graph.
 * @returns Number of components in graph.
 */
int count_components_dfs(const graf_t& graph);

#endif  // SRC_DFS_HPP_
