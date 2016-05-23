#include "strongly_connected_components.hpp"

#include <vector>
#include <algorithm>

void strong_connect(const weighted_graf_t& graph, std::vector<std::vector<int>>& components,
                    std::vector<int>& index, std::vector<int>& lowlink,
                    std::vector<int>& stack, int ind, int v) {
    index[v] = ind;
    lowlink[v] = ind;
    ind++;
    stack.push_back(v);

    for (const auto& edge : graph[v]) {
        int w = edge.first;
        if (index[w] == 0) {
            strong_connect(graph, components, index, lowlink, stack, ind, w);
            lowlink[v] = std::min(lowlink[v], lowlink[w]);
        } else if (index[w] != -1) {
            lowlink[v] = std::min(lowlink[v], index[w]);
        }
    }
    if (lowlink[v] == index[v]) {  // v is root node
        std::vector<int> component;
        int w;
        do {
            w = stack.back();
            stack.pop_back();
            component.push_back(w);
            index[w] = -1;
        } while (w != v);
        components.push_back(component);
    }
}

std::vector<std::vector<int>> strongly_connected_components(const weighted_graf_t& graph) {
    int n = graph.size(), ind = 0;
    std::vector<int> index(n, 0), lowlink(n, 0), stack;
    std::vector<std::vector<int>> components;
    for (int i = 0; i < n; ++i) {
        if (index[i] == 0) strong_connect(graph, components, index, lowlink, stack, ind, i);
    }
    return components;
}
