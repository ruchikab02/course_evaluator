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
  std::cout << "Enter a Course to run Betweeness Centrality on: ";
  std::getline(std::cin, input);
  int node_idx = graph.NameToIdx(input);
  std::ofstream output(outfile, std::ios::out);
  graph.BetweennessCentrality(node_idx, output);
  output.close();
  return 0;
}
