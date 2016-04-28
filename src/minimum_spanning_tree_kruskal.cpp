#include "minimum_spanning_tree_kruskal.hpp"

#include <vector>
#include <limits>
#include <algorithm>
#include <tuple>

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

double sum_of_paths_minimum_spanning_tree(const weighted_graf_t& graph) {
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
