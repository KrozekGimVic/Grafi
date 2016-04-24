#include "bellman_ford.hpp"

#include <vector>

vector<int> bellman_ford(const weighted_graf_t& graph, int vertex) {
    vector<int> distance(graph.size(), INFINITY);
    distance[vertex] = 0;

    for(int i = 1; i < graph.size(); i++){
	for(int u = 0; u < graph.size(); u++){
	    for(int v : graph[u]){
		if (distance[u] + v.second < distance[v.first])
		    distance[v.first] = distance[u] + v.second;
	    }
	}
    }
    for(int u = 0; u < graph.size(); u++){
	for(int v : graph[u]){
	    if (distance[u] + v.second < distance[v.first]) {
		vector<int> infinivector(graph.size(), -INFINITY);
		return infinivector;
	    }
	}
    }
    return distance;
}
