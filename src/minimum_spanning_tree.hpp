#ifndef SRC_MINIMUM_SPANNING_TREE_HPP_
#define SRC_MINIMUM_SPANNING_TREE_HPP_

#include <vector>

#include "utils.hpp"

/**
 * @file minimum_spanning_tree.hpp
 * @author Matej Marinko <matejmarinko123@gmail.com>
 * @author Bor Brecelj <bor.brecelj@gmail.com>
 * @brief Minimum spanning tree algorithm.
 */

/// Represents weighted edge.
struct Edge {
    int a;  ///< Starting vertex.
    int b;  ///< Ending vertex.
    double w;  ///< Weight of an edge.
    /// Comparison of weights of edges.
    bool operator<(const Edge& e) const;
};

int find(int a, std::vector<int>& parent);

bool union_components(int a, int b, std::vector<int>& parent, std::vector<int>& rank);

/**
 * @brief Creates minimum spanning tree from given undirected weighted graph.
 * @param graph A undirected weighted graph.
 * @returns Sum of weights on edges of minimum spanning tree. If minimum spanning
 * tree for given graph does not exist, returns max integer value. For empty graphs returns 0.
 */
double sum_of_paths_minimum_spanning_tree_kruskal(const weighted_graf_t& graph);

/**
 * @brief Creates minimum spanning tree from given undirected weighted graph
 * using Prim algorithm.
 * @param graph A undirected weighted graph.
 * @returns Sum of weights on edges of minimum spanning tree. If minimum spanning
 * tree for given graph does not exist, returns max integer value. For empty graphs returns 0.
 */
double sum_of_paths_minimum_spanning_tree_prim(const weighted_graf_t& graph);

#endif  //  SRC_MINIMUM_SPANNING_TREE_HPP_
