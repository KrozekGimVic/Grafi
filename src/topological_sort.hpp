#ifndef SRC_TOPOLOGICAL_SORT_HPP_
#define SRC_TOPOLOGICAL_SORT_HPP_

#include <vector>

#include "utils.hpp"

/**
 * @file topological_sort.hpp
 * @author Vid Drobnič <vid.drobnic@gmail.com>
 * @author Rok Kos <rocki5555@gmail.com>
 * @brief Algortihms for topological sorting.
 */

/**
 * Implementations details for topological sort algorithms.
 */
namespace topological_sort_internal {
/**
 * @brief topolgical_sort_helper_function
 * @param graph A directed graph
 * @param visited Vector of visited nodes, shared between function calls.
 * @param visited_vertices Vector of visited vertices, used to recognize cycles.
 * @param start_node Starting vertex for path search.
 * @returns Reversed topologically sorted vertices from starting vertex.
 */
std::vector<int> topological_sort(const graf_t& graph, std::vector<bool>& visited,
                                  std::vector<int> visited_vertices, int start_node);
}  // namespace topological_sort_internal

/**
 * @brief Topologically sorts a graph using dfs.
 * @param graph A directed graph.
 * @returns Topologically sorted vertices.
 */
std::vector<int> topological_sort_dfs(const graf_t& graph);

/**
 * @brief Topologically sort a graph.
 * Algorithm that sorts directed acyclic graph with dfs algorithm.
 * @param g an input graph
 * @return Topologically sorted graph.
 */
std::vector<int> topological_sort_bfs(const graf_t& g);

/**
 * @brief Check if a graph is topologically sorted according to the DAG given.
 * @param vertices Array of length n contaning ordered verices. The elements must be integers from 0
 * to n-1 inclusive.
 * @param dag Graph with n vertices which must be a DAG otherwise behaviour is undefined.
 * @return True if `vertices` are topologically sorted according to `dag` and false otherwise.
 */
bool is_topologically_sorted(const std::vector<int>& vertices, const graf_t& dag);

#endif  // SRC_TOPOLOGICAL_SORT_HPP_
