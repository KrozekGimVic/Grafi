#include "topological_sort.hpp"

#include <algorithm>
#include <queue>
#include <vector>

using std::vector;
namespace topological_sort_internal {
std::vector<int> topological_sort(const graf_t& graph, std::vector<bool>& visited,
                                  std::vector<int> visited_vertices, int start_node) {
    vector<int> indices = graph[start_node];
    visited[start_node] = true;
    visited_vertices.push_back(start_node);
    vector<int> result;

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
}  // namespace topological_sort_internal

vector<int> topological_sort_dfs(const graf_t &graph) {
    vector<bool> visited(graph.size(), false);
    vector<int> result;

    for (unsigned int i = 0; i < graph.size(); ++i) {
        if (visited[i]) {
            continue;
        }

        vector<int> visited_vertices = {static_cast<int>(i)};

        auto buff = topological_sort_internal::topological_sort(
            graph, visited, visited_vertices, i);
        if (buff.size() == 0) {
            return {};
        }

        result.insert(result.end(), buff.begin(), buff.end());
    }

    std::reverse(result.begin(), result.end());
    return result;
}

vector<int> topological_sort_bfs(const graf_t& g) {
    int N = g.size();  // size of graph

    vector<int> ind(N, 0);  // vector that hold how many path lead to current vertex

    // goes through graph and count path to each vertex
    for (int i = 0; i < N; ++i) {
        for (int v : g[i]) {
            ind[v]++;
        }
    }

    std::queue<int> q;  // queue that hold next vertex in line
    // push in queue all vertices that have no path leading to them
    for (int i = 0; i < N; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    vector<int> dag;  // our topological sorted graph
    vector<int> empty = {};  // vector that we return when graph is invalid

    while (!q.empty()) {
        // get first from queue
        int curInd = q.front();
        q.pop();
        dag.push_back(curInd);

        // go through all his neighbours
        for (int v : g[curInd]) {
            ind[v]--;

            // if vertex has no path to them then push this vertex in queue
            if (ind[v] == 0) {
                q.push(v);
            }

            // if we went through one vertex more than once
            // that means that there is cycle or this is invalid graph
            if (ind[v] < 0) {
                return empty;
            }
        }
    }

    int dag_size = dag.size();

    // if queue was empty before we went through all vertex that means that there was cycle
    if (dag_size < N) {
        return empty;
    }

    return dag;
}
