#ifndef SRC_FLOYD_WARSHALL_HPP_
#define SRC_FLOYD_WARSHALL_HPP_

#include <vector>
#include "utils.hpp"

/**
 * @file floyd_warshall.hpp
 * @author Vid Drobnič <vid.drobnic@gmail.com>
 * @brief Floyd-Warshall algorithm.
 */

/**
 * @brief Compares all possible paths through the graph.
 * @param graph A weighted graph.
 * @returns Matrix with minimum distance between all pairs of vertices.
 */
std::vector<std::vector<double>> floyd_warshall(const weighted_graf_t& graph);

#endif  // SRC_FLOYD_WARSHALL_HPP_
