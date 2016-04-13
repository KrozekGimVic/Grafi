#include "bfs.hpp"


int count_components_bfs(const graf_t& graph){
	std::vector<bool> visited(graph.size(), false);
	int num = 0;

	for (unsigned int i=0; i<graph.size(); ++i) {
		if (!visited[i]) {
			num++;
			std::queue<int> queue;
			queue.push(i);

			
			while (!queue.empty()) {
				int v = queue.front();
				queue.pop();

				if (!visited[v]) {
					visited[v] = true;
					for (int u: graph[v]) queue.push(u);
				}
			}
		}
	}
	return num;
}
