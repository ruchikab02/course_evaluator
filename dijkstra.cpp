#include "Graph/Graph.h"

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  // make sure a dataset and output file is inputted
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <DATASET> <OUTPUT>" << std::endl;
    return 1;
  }
  const std::string infile = argv[1];  // dataset (csv)
  const std::string outfile = argv[2];  // output (txt)
  // create graph object
  Graph graph(infile);
  // outputs Dijkstra's shortest path from a source node to any other node
  std::string input;
  std::cout << "Enter a Course to run Dijkstra's shortest path algorithm: ";
  std::getline(std::cin, input);
  int node_idx = graph.NameToIdx(input);
  std::ofstream output(outfile, std::ios::out);
  graph.Dijkstra(node_idx, output);
  output.close();
  // outputs Dijkstra's shortest path between 2 nodes
  std::cout << "Find a path between 2 nodes using Dijkstra. Enter the Course to start from: ";
  std::getline(std::cin, input);
  std::string input2;
  std::cout << "Enter the Course to end at: ";
  std::getline(std::cin, input2);
  node_idx = graph.NameToIdx(input);
  int node_idx2 = graph.NameToIdx(input2);
  output.open(outfile, std::ios::app);
  graph.Dijkstra(node_idx, node_idx2, output);
  output.close();
  return 0;
}
