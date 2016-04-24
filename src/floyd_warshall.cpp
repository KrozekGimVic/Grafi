#include "floyd_warshall.hpp"

std::vector<std::vector<double>> floyd_warshall(const weighted_graf_t& graph) {
    const int N = static_cast<int>(graph.size());
    std::vector<std::vector<double>> distance(N, std::vector<double>(N, INFINITY));

    for (int vertex_index = 0; vertex_index < N; ++vertex_index) {
        distance[vertex_index][vertex_index] = 0.;

        for (const auto& edge : graph[vertex_index]) {
            distance[vertex_index][edge.first] = edge.second;
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    return distance;
}
