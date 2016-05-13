#ifndef SRC_STRONGLY_CONNECTED_COMPONENTS_HPP_
#define SRC_STRONGLY_CONNECTED_COMPONENTS_HPP_

#include <vector>
#include "utils.hpp"

/**
 * @file strongly_connected_components.hpp
 * @author Matej Marinko <matejmarinko123@gmail.com>
 * @brief Algorithms based on strongly connected components.
 */

 /**
  * @brief Tarjan's strongly connected components algorithm.
  */
void strong_connect(const weighted_graf_t& graph, std::vector<std::vector<int>>& components,
                                        std::vector<int>& index, std::vector<int>& lowlink,
                                                    std::vector<int>& stack, int ind, int v);

/**
 * @brief Finds strongly connected components in a given graph.
 * @param graph A graph.
 * @returns Vector of strongly connected components. Each component is represented as
 * a vector of vertices. Note that components and vertices may not be in sorted order.
 */
std::vector<std::vector<int>> strongly_connected_components(const weighted_graf_t& graph);

#endif  //  SRC_STRONGLY_CONNECTED_COMPONENTS_HPP_
