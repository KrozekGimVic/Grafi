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

## Documentation
To generate documentation, go to `build/` and run
```
make docs
```
You need to have doxygen installed.

# Full test
Before each commit, please run `./full_test.sh` and make sure it completes without errors.
Only than can you commit. You can add it to your pre-commit hook.

Use `./full_test.sh --help` for usage instructions. Example run:
```
$ ./full_test.sh
Configuring ...
Detected Arch-like disto.
Checking build tools ...
    Checking g++ ...
    Checking g++ version is >= 4.8 ...
    Checking cmake ...
    Checking make ...
    Checking doxygen ...
Configuring done.
Looking for tests ...
All cpp files have tests.
Compiling tests ...
-- Configuring done
-- Generating done
-- Build files have been written to: /home/jureslak/prog/krozek/Grafi/build
[ 28%] Built target gtest
[ 50%] Built target grafi
[ 64%] Built target gtest_main
[100%] Built target tests
/home/jureslak/prog/krozek/Grafi
Running tests ...
Running main() from gtest_main.cc
[==========] Running 10 tests from 4 test cases.
[----------] Global test environment set-up.
[----------] 1 test from DfsTopologicalSort
[ RUN      ] DfsTopologicalSort.UniqueResult
[       OK ] DfsTopologicalSort.UniqueResult (0 ms)
[----------] 1 test from DfsTopologicalSort (0 ms total)

[----------] 1 test from topological_sort_bfs
[ RUN      ] topological_sort_bfs.UniqueResult
[       OK ] topological_sort_bfs.UniqueResult (0 ms)
[----------] 1 test from topological_sort_bfs (0 ms total)

[----------] 4 tests from CountComponentsBfs
[ RUN      ] CountComponentsBfs.Connected
[       OK ] CountComponentsBfs.Connected (0 ms)
[ RUN      ] CountComponentsBfs.Disconnected
[       OK ] CountComponentsBfs.Disconnected (0 ms)
[ RUN      ] CountComponentsBfs.EmptyGraph
[       OK ] CountComponentsBfs.EmptyGraph (0 ms)
[ RUN      ] CountComponentsBfs.NoEdges
[       OK ] CountComponentsBfs.NoEdges (0 ms)
[----------] 4 tests from CountComponentsBfs (0 ms total)

[----------] 4 tests from CountComponentsDfs
[ RUN      ] CountComponentsDfs.Connected
[       OK ] CountComponentsDfs.Connected (0 ms)
[ RUN      ] CountComponentsDfs.Disconnected
[       OK ] CountComponentsDfs.Disconnected (0 ms)
[ RUN      ] CountComponentsDfs.EmptyGraph
[       OK ] CountComponentsDfs.EmptyGraph (0 ms)
[ RUN      ] CountComponentsDfs.NoEdges
[       OK ] CountComponentsDfs.NoEdges (0 ms)
[----------] 4 tests from CountComponentsDfs (0 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 4 test cases ran. (0 ms total)
[  PASSED  ] 10 tests.
All tests compile and pass.
Checking code style ...
Code style check passed.
Checking docs ...
/home/jureslak/prog/krozek/Grafi
No undocumented features found.
All done, feel free to commit.
```

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
Maybe add Travis CI.

Fun times!

Jure
