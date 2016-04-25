#include "minimum_spanning_tree_kruskal.hpp"

#include <vector>
#include <limits>
#include <algorithm>
#include <tuple>

bool Edge::operator<(const Edge& e) const { return w < e.w; }

bool union_find(int a, int b, std::vector<int>& parent, std::vector<int>& rank) {
    int parent_a = a, parent_b = b;
    while (parent[parent_a] != parent_a) parent_a = parent[parent_a];
    while (parent[parent_b] != parent_b) parent_b = parent[parent_b];
    if (parent_a == parent_b) return false;

    if (rank[parent_a] < rank[parent_b]) {
        parent[parent_a] = parent_b;
    } else if (rank[parent_a] > rank[parent_b]) {
        parent[parent_b] = parent_a;
    } else {
        parent[parent_a] = parent_b;
        rank[parent_a]++;
    }
    return true;
}

int sum_of_paths_minimum_spanning_tree(const weighted_graf_t& graph) {
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
        if (union_find(e.a, e.b, parent, rank)) {
            sum += e.w;
            edge_count++;
        }
        if (edge_count == n - 1) break;
    }
    if (edge_count < n - 1) return std::numeric_limits<int>::max();
    return sum;
}
