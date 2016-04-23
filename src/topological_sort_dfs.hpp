#ifndef GRAFI_TOPOLOGICAL_SORT_DFS_HPP
#define GRAFI_TOPOLOGICAL_SORT_DFS_HPP

#include "typedefs.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

/**
 * @file topological_sort_dfs.hpp
 * @author Vid Drobnič <vid.drobnic@gmail.com>
 * @brief DFS Topological Sort.
 */

/**
 * @brief Topologically sorts a graph using dfs.
 * @param graph A directed graph.
 * @returns Topologically sorted vertices.
 */
std::vector<int> topologicalSortDfs(const graf_t& graph);

#endif //GRAFI_DFS_TOPOLOGICAL_SORT_HPP
