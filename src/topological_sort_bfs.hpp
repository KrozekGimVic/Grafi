#ifndef GRAFI_TOPOLOGICAL_SORT_BFS_HPP
#define GRAFI_TOPOLOGICAL_SORT_BFS_HPP

#include "typedefs.hpp"

#include <iostream>
#include <vector>
#include <queue>

std::vector<int> topological_sort_bfs(const graf_t& g);

#endif  // GRAFI_TOPOLOGICAL_SORT_BFS_HPP