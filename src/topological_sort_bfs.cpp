#include "topological_sort_bfs.hpp"

using std::vector;

vector<int> topological_sort_bfs(const graf_t& g) {
    int N = g.size();  // size of graph

    vector<int> ind(N, 0);  // vector that hold how many path lead to current vertex

    // goes thru graph and count path to each vertex
    for (int i = 0; i < N; ++i) {
        for (int v : g[i]) {
            ind[v]++;
        }
    }

    std::queue<int> q;  // queue that hold next vertex in line
    // push in queue all vertax that have no path leading to them
    for (int i = 0; i < N; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    vector<int> dag;  // our topological sorted graph
    vector<int> empty = {};  // vector that we return when graph is invalid

    while (!q.empty()) {
        // get firts from queue
        int curInd = q.front();
        q.pop();
        dag.push_back(curInd);

        // go thru all his neighbours
        for (int v : g[curInd]) {
            ind[v]--;

            // if vertex has no path to them then push this vertex in queue
            if (ind[v] == 0) {
                q.push(v);
            }

            // if we went thru one vertex more than once
            // that means that there is cycle or this is invalid graph
            if (ind[v] < 0) {
                return empty;
            }
        }
    }

    int dag_size = dag.size();

    // if queue was empty before we went thru all vertex that means that there was cycle
    if (dag_size < N) {
        return empty;
    }

    return dag;
}
