#include "minimum_spanning_tree.hpp"

#include <vector>
#include <limits>
#include <algorithm>
#include <tuple>
#include <queue>
#include <functional>
#include <utility>

bool Edge::operator<(const Edge& e) const { return w < e.w; }

int find(int a, std::vector<int>& parent) {
    if (parent[a] != a) parent[a] = find(parent[a], parent);
    return parent[a];
}

bool union_components(int a, int b, std::vector<int>& parent, std::vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);
    if (a == b) return false;

    if (rank[a] < rank[b]) {
        parent[a] = b;
    } else if (rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
        rank[a]++;
    }
    return true;
}

double sum_of_paths_minimum_spanning_tree_kruskal(const weighted_graf_t& graph) {
    int n = graph.size();
    std::vector<Edge> edges;
    for (int v = 0; v < n; ++v) {
        int u;
        double w;
        for (const auto& pair : graph[v]) {
            std::tie(u, w) = pair;
            edges.push_back({v, u, w});
        }
    }
    std::sort(edges.begin(), edges.end());
    double sum = 0;
    int edge_count = 0;
    std::vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    for (const Edge& e : edges) {
        if (union_components(e.a, e.b, parent, rank)) {
            sum += e.w;
            edge_count++;
        }
        if (edge_count == n - 1) break;
    }
    if (edge_count < n - 1) return INFINITY;
    return sum;
}

double sum_of_paths_minimum_spanning_tree_prim(const weighted_graf_t& graph) {
    int n = graph.size(), count = 1, u;
    std::priority_queue< std::pair<double, int>, std::vector< std::pair<double, int> >,
        std::greater< std::pair<double, int> > > q;
    double sum = 0, w;
    std::vector<bool> visited(n, false);
    for (const auto& pair : graph[0]) {
        std::tie(u, w) = pair;
        q.push({w, u});
    }
    visited[0] = true;
    while (count < n && !q.empty()) {
        std::pair<double, int> node;
        node = q.top();
        std::tie(w, u) = node;
        q.pop();
        if (visited[u]) continue;
        sum += w;
        count++;
        for (const auto& pair : graph[u]) {
            int v;
            double weight;
            std::tie(v, weight) = pair;
            if (!visited[v]) q.push({weight, v});
        }
        visited[u] = true;
    }
    if (count < n) return INFINITY;
    return sum;
}
