#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <vector>
#include <utility>
#include <limits>

/**
 * @file utils.hpp
 * @brief Typedefs & classes.
 */

/// Represents a directed graph.
typedef std::vector<std::vector<int>> graf_t;

/// Represents a directed weighted graph.
typedef std::vector<std::vector<std::pair<int, double>>> weighted_graf_t;

/// Represents infinity.
const double INFINITY = std::numeric_limits<double>::infinity();

#endif  // SRC_UTILS_HPP_
