#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <vector>
#include <utility>

/**
 * @file utils.hpp
 * @brief Typedefs & classes.
 */

/// Represents a directed graph.
typedef std::vector<std::vector<int>> graf_t;

/// @brief Represents a directed weighted graph.
typedef std::vector<std::vector<std::pair<int, int>>> weighted_graf_t;

const double INFINITY = 1.0 / 0.0;

#endif  // SRC_UTILS_HPP_
