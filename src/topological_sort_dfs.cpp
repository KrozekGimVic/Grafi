#include "topological_sort_dfs.hpp"

std::vector<int> topologicalSort(const graf_t& graph, std::vector<bool>& visited, int startNode) {
    std::vector<int> indices = graph[startNode];

    visited[startNode] = true;

    std::vector<int> result;

    for (int index : indices) {
        if (visited[index]) {
            continue;
        }

        auto buff = topologicalSort(graph, visited, index);
        result.insert(result.end(), buff.begin(), buff.end());
    }

    result.push_back(startNode);
    return result;
}

std::vector<int> topologicalSortDfs(const graf_t& graph) {
    std::vector<bool> visited(graph.size(), false);

    std::vector<int> result;

    for (int i = 0; i < graph.size(); ++i) {
        if (visited[i]) {
            continue;
        }

        auto buff = topologicalSort(graph, visited, i);
        result.insert(result.end(), buff.begin(), buff.end());
    }

    std::reverse(result.begin(), result.end());
    return result;
}
