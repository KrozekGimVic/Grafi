#ifndef SRC_BFS_HPP_
#define SRC_BFS_HPP_

#include "utils.hpp"

/**
 * @file bfs.hpp
 * @author Matej Marinko <matejmarinko123@gmail.com>
 * @brief Breadth first search.
 */

/**
 * @brief Counts components of a graph using breadth first search.
 * @param graph A directed graph.
 * @returns Number of components in graph.
 */
int count_components_bfs(const graf_t& graph);

#endif  // SRC_BFS_HPP_
