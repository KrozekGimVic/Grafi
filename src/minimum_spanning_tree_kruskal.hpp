#ifndef SRC_MINIMUM_SPANNING_TREE_KRUSKAL_HPP_
#define SRC_MINIMUM_SPANNING_TREE_KRUSKAL_HPP_

#include "utils.hpp"
#include <vector>
#include <limits>
#include <algorithm>
#include <tuple>
#include <iostream>

/**
 * @file minimum_spanning_tree_kruskal.hpp
 * @author Matej Marinko <matejmarinko123@gmail.com>
 * @brief Kruskal's minimum spanning tree algorithm.
 */

/// @brief Represents weighted edge from vertex a to vertex b, with weight w.
struct edge {
    int a, b, w;
    bool operator<(const edge& e) const {
        return w < e.w;
    }
};

/**
 * @brief Creates minimum spanning tree from given undirected weighted graph.
 * @param graph A undirected weighted graph.
 * @returns Sum of weights on edges of minimum spanning tree. If mimimum spanning
 * tree for given graph does not exist, returns max integer value. For empty graphs returns 0.
 */
int sum_of_paths_minimum_spanning_tree(const weighted_graf_t& graph);

#endif  //  SRC_MINIMUM_SPANNING_TREE_KRUSKAL_HPP_
