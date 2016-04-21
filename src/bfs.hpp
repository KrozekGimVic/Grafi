#ifndef SRC_BFS_HPP_
#define SRC_BFS_HPP_

#include "typedefs.hpp"

/**
 * @file bfs.hpp
 * @author Matej Marinko <matejmarinko123@gmail.com>
 */

/**
 * @brief Counts components of a graph.
 * @param grapg A directed graph.
 * @returns Number of components in graph.
 */

int count_components_bfs(const graf_t& graph);

#endif  // SRC_BFS_HPP_
