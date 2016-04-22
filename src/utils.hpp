#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <vector>
#include <utility>

/**
 * @file utils.hpp
 */

/// Represents a directed graph.
typedef std::vector<std::vector<int>> graf_t;

/// @brief Represents a directed weighted graph.
typedef std::vector<std::vector<std::pair<int, int>>> weighted_graf_t;



#endif  // SRC_UTILS_HPP_
