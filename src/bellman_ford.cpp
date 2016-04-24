#include "bellman_ford.hpp"

#include <vector>
using std::vector;

vector<double> bellman_ford(const weighted_graf_t& graph, int vertex) {
    vector<double> distance(graph.size(), INFINITY);
    distance[vertex] = 0;
    
    const int N = static_cast<int>(graph.size());
    
    for(int i = 1; i < N; i++){
    for(int u = 0; u < N; u++){
        for(std::pair<int, int> v : graph[u]){
        if (distance[u] + v.second < distance[v.first])
            distance[v.first] = distance[u] + v.second;
        }
    }
    }
    for(int u = 0; u < N; u++){
    for(std::pair<int, int> v : graph[u]){
        if (distance[u] + v.second < distance[v.first]) {
        vector<double> infinivector(graph.size(), -INFINITY);
        return infinivector;
        }
    }
    }
    return distance;
}
