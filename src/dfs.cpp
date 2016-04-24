#include "dfs.hpp"

#include <vector>

using std::vector;

void dfs(int pos, vector<bool>& v, const graf_t& g) {
    v[pos] = true;
    int l = g[pos].size();
    for (int i = 0; i < l; ++i) {
        if (!v[g[pos][i]]) {
            dfs(g[pos][i], v, g);
        }
    }
}

int count_components_dfs(const graf_t& g) {
    int num_of_components = 0, n = g.size();
    vector<bool> v(n, false);
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            ++num_of_components;
            dfs(i, v, g);
        }
    }
    return num_of_components;
}
