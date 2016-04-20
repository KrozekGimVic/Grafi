#include "topological_sort_bfs.hpp"

using std::vector;
vector<int> topological_sort_bfs(const graf_t& g){
	
	int N = g.size();

	vector<int> ind(N, 0);

	for(int i = 0; i < N; ++i){
		for(int v : g[i]){
			ind[v]++;
		}
	}

	std::queue<int> q;
	
	for (int i = 0; i < ind.size(); ++i){
		if(ind[i] == 0){
			q.push(i);	
		} 
	}

	vector<int> dag;

	while(!q.empty()){

		int curInd = q.front();
		q.pop();

		dag.push_back(curInd);

		for(int v : g[curInd]){
			ind[v]--;
			if(ind[v] == 0){
				q.push(v);
			}
			
		}

	}

	return dag;
}