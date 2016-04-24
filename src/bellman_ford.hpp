#ifndef SRC_BELLMAN_FORD_HPP_
#define SRC_BELLMAN_FORD_HPP_

#include <vector>
#include "utils.hpp"
/**
 * @file bellman_ford.hpp
 * @author Bor Grošelj Simić <bor.groseljsimic@telemach.net>
 * @brief Implementation of Bellman-Ford algorithm
 */

/**
 * @brief Computes weights from base vertex for whole graph.
 * @param graph The input graph
 * @param vertex The vertex from which distances are measured
 * @returns Vector of distances from the base vertex
 */
std::vector<double> bellman_ford(const weighted_graf_t& graph, int vertex);

#endif  // SRC_BELLMAN_FORD_HPP_
