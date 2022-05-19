#pragma once
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <fstream>
#include <sstream>
#include <utility>
#include <climits>
#include <algorithm>

/**
 * Graph class: stores an adjacency matrix of Edge pointers
 * as well as a map of node names (strings) to Node pointers
 * 
 */
class Graph {
 public:

  /**
   * Graph constructor
   * @param filename : takes in a file and reads it and makes nodes and edges  
   */
  Graph(std::string filename);

  /**
   * Destructor for graph
   */
  ~Graph(); 


  void print() const;

  // graph operations:

  /**
   * Checks to see if a node is pointing to another node
   * @param origin - the origin node
   * @param dest - the destination node
   */
  bool pointsTo(const Node* origin, const Node* dest) const;

  /**
   * Checks to see if two nodes are adjacent
   * @param origin - the origin node
   * @param dest - the destination node
   */
  bool areAdjacent(const Node* origin, const Node* dest) const;


  // graph algorithms:
  /**
   * Performs a Breadth-First Traveral on all nodes of a graph
   */
  void BFS(std::ofstream& output);

  /**
  * @param n Index of the source node from which to start the BFS
  * @param visited Vector of booleans to keep track of which nodes have been visited
  */
  void BFS(int n, std::vector<bool>& visited, std::ofstream& output);

  /**
  * @param n Index of the source node from which to start the BFS
  */
  void BFS(int n, std::ofstream& output);

  /**
   * Dijkstras' algorithm for the shortest path
   * @param n : we will calculate the shortest path of all nodes from this node
   */
  void Dijkstra(int start, int end, std::ofstream& output);
  void Dijkstra(int n, std::ofstream& output);
  void DijkstraForBC(int n);

  /**
   * Finds the Betweenness Centrality for all the nodes in a graph
   */
  void BetweennessCentrality(std::ofstream& output);

  /**
   * Helper method for BetweennessCentrality();
   * @param idx - the index of a node
   * @return a double to represent the betweenness centrality at a given index
   */
  double BetweennessCentrality(int idx, std::ofstream& output);

  /**
   * @param name of the node
   * @return the index of a node
   */
  int NameToIdx(std::string name) const;
  
  /**
   * @return the number of nodes in the graph
   */
  size_t getNumNodes() const { return num_nodes_; }

  /**
   * @return the number of edges in the graph
   */
  size_t getNumEdges() const { return num_edges_; }
  
  /**
   * @return the string to Node* map - used for testing
   */
  std::map<std::string, const Node*>& getNodes() { return nodes_; }

  /**
   * Finds an edge between two nodes, or returns nullptr
   * @param origin the origin node
   * @param dest the destination node
   * @return the edge between the two nodes, or returns nullptr
   */
  const Edge* getEdge(const Node* origin, const Node* dest) const { return adj_matrix_.at(origin->getIndex()).at(dest->getIndex()); }

 private:
  /**
   * Internal representation: map of nodes and adjacency matrix of edge pointers
   */
  std::map<std::string, const Node*> nodes_;
  std::vector<std::vector<Edge*> > adj_matrix_;
  size_t num_nodes_ = 0;
  size_t num_edges_ = 0;

  std::vector<std::string> name_vec_;
  std::vector<std::vector<int>> paths_;

  /**
   * Inserts a node into the graph
   * @param node the node to be inserted
   * @param name the name of the node to be inserted
   */
  void insertNode(const Node* node, const std::string name);

  /**
   * Inserts an edge into the graph
   * @param origin origin node of the edge to be inserted
   * @param dest  destination node of the edge to be inserted
   */
  void insertEdge(const Node* origin, const Node* dest);

  /**
   * Helper method used for parsing
   * @param string to be split
   * @param delim character delimiter at which to split the string
   */
  std::vector<std::string> tokenize(const std::string, const char delim) const;

  /**
   * Checks to see if a vector contains the node at a given index
   * @param idx index of the node
   * @param vec vector of node indeces
   */
  bool contains(int idx, std::vector<int>& vec) const;

  /**
   * Prints out nodes for Dijkstras'
   * @param parent vector of ints
   * @param output for outputting to file
   */
  void printPath(std::vector<int>& parent, int j, std::ofstream& output);

  /**
   * Adds a path to the 2d vector paths_
   * @param parent original vector
   * @param vec new vector to append data to
   */
  void addPath(std::vector<int>& parent, int j, std::vector<int>& new_vec);
  
};
