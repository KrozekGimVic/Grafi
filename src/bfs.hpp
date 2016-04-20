#ifndef GRAFI_SRC_BFS_HPP
#define GRAFI_SRC_BFS_HPP

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

#endif //GRAFI_SRC_BFS_HPP