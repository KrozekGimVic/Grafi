#include "topological_sort_dfs.hpp"

#include <vector>
#include <algorithm>

std::vector<int> topological_sort_dfs_internal::topological_sort(const graf_t &graph,
                                        std::vector<bool> &visited, int start_node) {
    std::vector<int> indices = graph[start_node];

    visited[start_node] = true;

    std::vector<int> result;

    for (int index : indices) {
        if (visited[index]) {
            continue;
        }

        auto buff = topological_sort(graph, visited, index);
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

        auto buff = topological_sort_dfs_internal::topological_sort(graph, visited, i);
        result.insert(result.end(), buff.begin(), buff.end());
    }

    std::reverse(result.begin(), result.end());
    return result;
}
