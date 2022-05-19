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
  // output a full BFS traversal on the whole graph & the # of connected components
  std::ofstream output(outfile, std::ios::out);
  graph.BFS(output);
  output.close();
  // run a BFS traversal within its connected component
  std::string input;
  std::cout << "Enter a Course to run the BFS traversal within its connected component: ";
  std::getline(std::cin, input);
  int node_idx = graph.NameToIdx(input);
  output.open(outfile, std::ios::app);
  graph.BFS(node_idx, output);
  output.close();
  return 0;
}
