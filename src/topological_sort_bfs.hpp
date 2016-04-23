#ifndef SRC_TOPOLOGICAL_SORT_BFS_HPP_
#define SRC_TOPOLOGICAL_SORT_BFS_HPP_

#include "typedefs.hpp"

#include <iostream>
#include <vector>
#include <queue>

std::vector<int> topological_sort_bfs(const graf_t& g);

#endif  // SRC_TOPOLOGICAL_SORT_BFS_HPP_
