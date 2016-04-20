#include "bfs.hpp"

#include <vector>
#include <queue>

int count_components_bfs(const graf_t& graph){
    int num = 0, n = graph.size();
    std::vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
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
