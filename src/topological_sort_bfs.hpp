#ifndef SRC_TOPOLOGICAL_SORT_BFS_HPP_
#define SRC_TOPOLOGICAL_SORT_BFS_HPP_

#include "typedefs.hpp"

#include <iostream>
#include <vector>
#include <queue>

/**
 * @file: topological_sort_bfs.cpp
 * @author: Rok Kos <rocki5555@gmail.com>
 * @date: 20.04.2016
 * @brief Topological bfs sort
 */

/**
 * @brief Topologicaly sort graph
 * 
 * Algorithm that sorts directed acyclic graph wiht dfs algorihtm.
 * 
 * @param g an input graph
 * 
 * @return Topological sorted graph 
 * 
 */

std::vector<int> topological_sort_bfs(const graf_t& g);

#endif  // SRC_TOPOLOGICAL_SORT_BFS_HPP_
