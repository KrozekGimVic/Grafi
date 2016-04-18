# Grafi

Learning graph algorithms.

## Instalation and running tests
Run
```
git clone git@github.com:KrozekGimVic/Grafi.git
```
Go to root folder of the repository and do the usual compile & run cycle:
```
mkdir -p build
cd build
cmake ..
make
../bin/tests
```
If all tests appear green, you are good to go.

## Work done so far
* number of connected components using BSF and DFS
* topological sort on DAG using BFS and DFS

# Plan
* path from vertex to vertex
* shortest / longest path in DAG
* shortest path Dijkstra
* shortest path Bellman-Ford
* shortest path Floyd-Warshall
* minimal spanning tree Prim
* union-find, minimal spanning tree Kruskal
* strongly connected components
* lowest common ancestor
* max-flow / min-cut Edmonds-Karp
* max bipartite matching, min vertex cover
* articulation points and bridges
* ...

## TODO
Add style checher, doxygen generated docs and maybe Travic CI.

Fun times!

Jure
