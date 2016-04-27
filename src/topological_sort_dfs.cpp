#include "topological_sort_dfs.hpp"

#include <vector>
#include <algorithm>

std::vector<int> topological_sort_dfs_internal::topological_sort(
        const graf_t& graph, std::vector<bool>& visited, std::vector<int> visited_vertices, int start_node) {

    std::vector<int> indices = graph[start_node];
    visited[start_node] = true;
    visited_vertices.push_back(start_node);
    std::vector<int> result;

    for (int index : indices) {
        for (int vertex : visited_vertices) {
            if (vertex == index) {
                return {};
            }
        }

        if (visited[index]) {
            continue;
        }
        auto buff = topological_sort(graph, visited, visited_vertices, index);
        if (buff.size() == 0) {
            return {};
        }

        result.insert(result.end(), buff.begin(), buff.end());
    }

    result.push_back(start_node);
    return result;
}

std::vector<int> topological_sort_dfs(const graf_t &graph) {
    std::vector<bool> visited(graph.size(), false);

    std::vector<int> result;

    for (unsigned int i = 0; i < graph.size(); ++i) {
        if (visited[i]) {
            continue;
        }

        std::vector<int> visited_vertices = {static_cast<int>(i)};

        auto buff = topological_sort_dfs_internal::topological_sort(graph, visited, visited_vertices, i);
        if (buff.size() == 0) {
            return {};
        }

        result.insert(result.end(), buff.begin(), buff.end());
    }

    std::reverse(result.begin(), result.end());
    return result;
}
