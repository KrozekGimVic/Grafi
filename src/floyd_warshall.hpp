#ifndef GRAFI_FLOYD_WARSHALL_HPP
#define GRAFI_FLOYD_WARSHALL_HPP

#include "utils.hpp"
#include <vector>


/**
 * @file floyd_warshall.hpp
 * @author Vid Drobnič <vid.drobnic@gmail.com>
 * @brief Floyd-Warshall algorithm.
 */


/**
 * @brief Compares all possible paths through the graph.
 * @param graph A weighted graph
 * @returns Matrix with minimum distance between vertices.
 */
std::vector<std::vector<double>> floyd_warshall(const weighted_graf_t& graph);


#endif //GRAFI_FLOYD_WARSHALL_HPP
