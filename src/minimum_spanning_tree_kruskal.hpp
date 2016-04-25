#ifndef SRC_MINIMUM_SPANNING_TREE_KRUSKAL_HPP_
#define SRC_MINIMUM_SPANNING_TREE_KRUSKAL_HPP_

#include "utils.hpp"

/**
 * @file minimum_spanning_tree_kruskal.hpp
 * @author Matej Marinko <matejmarinko123@gmail.com>
 * @brief Kruskal's minimum spanning tree algorithm.
 */

/// @brief Represents weighted edge.
struct edge {
    /// Starting vertex.
    int a;
    /// Ending vertex.
    int b;
    /// Weight of an edge.
    int w;
    /// Comparison of weights of edges.
    bool operator<(const edge& e) const { return w < e.w; }
};

/**
 * @brief Creates minimum spanning tree from given undirected weighted graph.
 * @param graph A undirected weighted graph.
 * @returns Sum of weights on edges of minimum spanning tree. If minimum spanning
 * tree for given graph does not exist, returns max integer value. For empty graphs returns 0.
 */
int sum_of_paths_minimum_spanning_tree(const weighted_graf_t& graph);

#endif  //  SRC_MINIMUM_SPANNING_TREE_KRUSKAL_HPP_
