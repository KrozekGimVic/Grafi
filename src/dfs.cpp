#include "dfs.hpp"

#include <vector>

using std::vector;

void dfs(int pos, vector<bool>& v, const graf_t& graph) {
    v[pos] = true;
    int l = graph[pos].size();
    for (int i = 0; i < l; ++i) {
        if (!v[graph[pos][i]]) {
            dfs(graph[pos][i], v, graph);
        }
    }
}

int count_components_dfs(const graf_t& graph) {
    int num_of_components = 0, n = graph.size();
    vector<bool> v(n, false);
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            ++num_of_components;
            dfs(i, v, graph);
        }
    }
    return num_of_components;
}
