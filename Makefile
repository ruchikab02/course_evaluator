CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

.PHONY: all bfs dijkstra betweenness test_graph test_algo clean

all: bfs dijkstra betweenness

bfs: bfs.cpp Graph/Graph.cpp Graph/Graph.h Graph/Node.h Graph/Edge.h
	${CXX} ${CXX_FLAGS} bfs.cpp Graph/Graph.cpp -o bin/bfs

dijkstra: dijkstra.cpp Graph/Graph.cpp Graph/Graph.h Graph/Node.h Graph/Edge.h
	${CXX} ${CXX_FLAGS} dijkstra.cpp Graph/Graph.cpp -o bin/dijkstra

betweenness: betweenness.cpp Graph/Graph.cpp Graph/Graph.h Graph/Node.h Graph/Edge.h
	${CXX} ${CXX_FLAGS} betweenness.cpp Graph/Graph.cpp -o bin/betweenness

test: test_graph test_algo

test_graph: tests/test_graph_imp.cpp Graph/Graph.cpp Graph/Graph.h Graph/Node.h Graph/Edge.h
	${CXX} ${CXX_FLAGS} tests/test_graph_imp.cpp Graph/Graph.cpp -o bin/test_graph_imp

test_algo: tests/test_graph_algo.cpp Graph/Graph.cpp Graph/Graph.h Graph/Node.h Graph/Edge.h
	${CXX} ${CXX_FLAGS} tests/test_graph_algo.cpp Graph/Graph.cpp -o bin/test_graph_algo

clean:
	rm -f bin/* *.o
