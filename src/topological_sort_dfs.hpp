#ifndef GRAFI_TOPOLOGICAL_SORT_DFS_HPP
#define GRAFI_TOPOLOGICAL_SORT_DFS_HPP

#include "utils.hpp"
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
std::vector<int> topological_sort_dfs(const graf_t& graph);

namespace topological_sort_dfs_internal {
    std::vector<int> topological_sort(const graf_t &graph, std::vector<bool> &visited, int startNode);
}

#endif //GRAFI_DFS_TOPOLOGICAL_SORT_HPP
