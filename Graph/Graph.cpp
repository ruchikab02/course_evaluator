#include "Graph.h"

// constructor (builds graph and reads in CSV)
Graph::Graph(std::string filename) {
  std::ifstream infile;
  infile.open(filename);
  if (!infile.is_open()) {
    std::cout << "unable to open file: " << filename << std::endl;
    return;
  }
  std::vector<std::vector<std::string>> vec;
  std::string line;
  std::getline(infile, line);
  while (std::getline(infile, line)) {
    std::vector<std::string> row = tokenize(line, ',');
    vec.push_back(row);
    Node* new_node = new Node(row.at(0), std::stod(row.at(1)), num_nodes_);
    insertNode(new_node, row.at(0));
  }
  for (size_t i = 0; i < vec.size(); ++i) {
    std::string name = vec.at(i).at(0);
    for (size_t j = 3; j < vec.at(i).size(); ++j) {
      if (nodes_.count(vec.at(i).at(j)) == 1) {
        insertEdge(nodes_[vec.at(i).at(j)], nodes_[name]);
      }
    }
  }

}

// destructor
Graph::~Graph() {
  for (auto& n : nodes_) {
    if (n.second != nullptr) {
      delete n.second;
      n.second = nullptr;
    }
  }
  for (size_t i = 0; i < adj_matrix_.size(); ++i) {
    for (size_t j = 0; j < adj_matrix_.at(i).size(); ++j) {
      if (adj_matrix_.at(i).at(j) != nullptr) {
        delete adj_matrix_.at(i).at(j);
        adj_matrix_.at(i).at(j) = nullptr;
      }
    }
  }
}

bool Graph::pointsTo(const Node* origin, const Node* dest) const {
  return adj_matrix_.at(origin->getIndex()).at(dest->getIndex());
}

bool Graph::areAdjacent(const Node* origin, const Node* dest) const {
  return adj_matrix_.at(origin->getIndex()).at(dest->getIndex()) || adj_matrix_.at(dest->getIndex()).at(origin->getIndex());
}

void Graph::insertNode(const Node* node, const std::string name) {
  num_nodes_++;
  nodes_.insert(std::pair<std::string, const Node*>(name, node));
  name_vec_.push_back(name);
  for (size_t i = 0; i < adj_matrix_.size(); ++i) {
    adj_matrix_.at(i).push_back(nullptr);
  }
  std::vector<Edge*> row(adj_matrix_.size()+1, nullptr);
  adj_matrix_.push_back(row);
}

void Graph::insertEdge(const Node* origin, const Node* dest) {
  if (adj_matrix_.at(origin->getIndex()).at(dest->getIndex()) == nullptr) {
    num_edges_++;
    Edge* new_edge = new Edge(origin, dest);
    adj_matrix_.at(origin->getIndex()).at(dest->getIndex()) = new_edge;
  }
}

void Graph::print() const {
  std::cout << "GRAPH: " << std::endl;
  for (auto const& node : nodes_) {
    std::cout << node.first << ": " << node.second->getWeight() << std::endl;
  }
  std::cout << "map: " << nodes_.size() << std::endl;
}

std::vector<std::string> Graph::tokenize(const std::string str, const char delim) const {
  std::vector<std::string> out;
  size_t start;
  size_t end = 0;
  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
  return out;
}

void Graph::BFS(std::ofstream& output) {
  if (!output.is_open()) {
    return;
  }
  output << "BFS Traversal of Entire Graph (including disconnected components): " << std::endl;
  // set all nodes as not visited
  std::vector<bool> visited(num_nodes_, false);
  int num_component = 0;
  for (const auto& node : nodes_) {
    int node_idx = node.second->getIndex();
    if (!visited.at(node_idx)) {
      BFS(node_idx, visited, output);
      num_component++;
    }
  }
  output << std::endl;
  output << "Total number of connected components: " << num_component << std::endl;
  output << std::endl;
}

void Graph::BFS(int n, std::vector<bool>& visited, std::ofstream& output) {
  std::queue<int> queue;
  // visit the current node & enqueue it
  visited.at(n) = true;
  queue.push(n);
  while(!queue.empty()) {
    // dequeue a node from queue
    n = queue.front();
    std::string node_name = name_vec_.at(n);
    double node_gpa = (nodes_[node_name])->getWeight();
    output << node_name << "  " << 4.0 - node_gpa << std::endl;
    queue.pop();
    // get all nodes that the dequeued node points to
    // if not visited, visit the node and enqueue it
    for (size_t i = 0; i < adj_matrix_.at(n).size(); ++i) {
      if (adj_matrix_.at(n).at(i) != nullptr && !visited.at(i)) {
        visited.at(i) = true;
        queue.push(i);
      }
    }
  }
}

void Graph::BFS(int n, std::ofstream& output) {
  if (!output.is_open()) {
    return;
  }
  output << "BFS Traversal on " << name_vec_.at(n) << " within its connnected component: " << std::endl;
  std::queue<int> queue;
  // set all nodes as not visited
  std::vector<bool> visited(num_nodes_, false);
  // visit the current node & enqueue it
  visited.at(n) = true;
  queue.push(n);
  while(!queue.empty()) {
    // dequeue a node from queue
    n = queue.front();
    std::string node_name = name_vec_.at(n);
    double node_gpa = (nodes_[node_name])->getWeight();
    output << node_name << "  " << 4.0 - node_gpa << std::endl;
    queue.pop();
    // get all nodes that the dequeued node points to
    // if not visited, visit the node and enqueue it
    for (size_t i = 0; i < adj_matrix_.at(n).size(); ++i) {
      if (adj_matrix_.at(n).at(i) != nullptr && !visited.at(i)) {
        visited.at(i) = true;
        queue.push(i);
      }
    }
  }
}


double Graph::BetweennessCentrality(int idx, std::ofstream& output)  {
  // for every node set BC = 0
  double betweenness_cent = 0;
  for (int i = 0; i < num_nodes_; i++) {
    DijkstraForBC(i);
    for (int j = 0; j < paths_.size(); j++) {
      if (contains(idx, paths_.at(j))) {
        betweenness_cent += (1 / paths_.at(j).size() - 1);
      }
    }
  }
  output << "Betweenness Centrality for " << name_vec_.at(idx) << ": " << betweenness_cent << std::endl;
  return betweenness_cent;
}

void Graph::BetweennessCentrality(std::ofstream& output) {
  for (int i = 0; i < num_nodes_; i++) {
    output << "Betweenness Centrality for " << name_vec_.at(i) << ": " << BetweennessCentrality(i, output);
  }
}

bool Graph::contains(int idx, std::vector<int>& vec) const {
  for (int i = 0; i < vec.size(); i++) {
    if (vec.at(i) == idx) {
      return true;
    }
  }
  return false;
}

void Graph::Dijkstra(int start, int end, std::ofstream& output) {
  if (!output.is_open()) {
    return;
  }
  // priority queue min heap
  std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>> , std::greater<std::pair<double, int>>> pq;
  // to store the paths
  std::vector<int> paths(num_nodes_, -1);
  // distances from n
  std::vector<double> dist(num_nodes_, INT_MAX);
  
  // push n onto priority q with distance 0
  pq.push(std::make_pair(0, start));
  dist.at(start) = 0;
  
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    // for all nodes that u points to
    for (size_t i = 0; i < adj_matrix_.at(u).size(); ++i) {
      if (adj_matrix_.at(u).at(i)) {
        double weight = adj_matrix_.at(u).at(i)->getWeight();
        // if there is shortest path to from u to i
        if (dist.at(i) > dist.at(u) + weight) {
          dist.at(i) = dist.at(u) + weight;
          pq.push(std::make_pair(dist.at(i), i));
          paths.at(i) = u;
        }
      }
    }
  }
  // print result
  output << "Shortest path from " << name_vec_.at(start) << " to " << name_vec_.at(end) << " using Dijkstra's:" << std::endl;
  if (dist.at(start) == INT_MAX) {
    output << "No path from " << name_vec_.at(start) << " to " << name_vec_.at(end) << std::endl;
  } else {
    // output << "Start->End Node: Distance from Start to End Node, Shortest path from Start to End Node" << std::endl;
    // output << name_vec_.at(start) << "->" << name_vec_.at(end) << ": " << dist.at(start) << ", Path: ";
    output << name_vec_.at(start) << " ";
    printPath(paths, end, output);
    output << std::endl;
  }
  output << std::endl;
}

void Graph::Dijkstra(int n, std::ofstream& output) {
  if (!output.is_open()) {
    return;
  }
  // priority queue min heap
  std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>> , std::greater<std::pair<double, int>>> pq;
  // to store the paths
  std::vector<int> paths(num_nodes_, -1);
  // distances from n
  std::vector<double> dist(num_nodes_, INT_MAX);
  
  // push n onto priority q with distance 0
  pq.push(std::make_pair(0, n));
  dist.at(n) = 0;
  
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    // for all nodes that u points to
    for (size_t i = 0; i < adj_matrix_.at(u).size(); ++i) {
      if (adj_matrix_.at(u).at(i)) {
        double weight = adj_matrix_.at(u).at(i)->getWeight();
        // if there is shortest path to from u to i
        if (dist.at(i) > dist.at(u) + weight) {
          dist.at(i) = dist.at(u) + weight;
          pq.push(std::make_pair(dist.at(i), i));
          paths.at(i) = u;
        }
      }
    }
  }
  // print result
  output << "Dijkstra's with " << name_vec_.at(n) << " as Start Node:" << std::endl;
  output << "Start->End Node: Distance from Start to End Node, Shortest path from Start to End Node" << std::endl;
  for (size_t i = 0; i < num_nodes_; ++i) {
    if (dist.at(i) == INT_MAX) {
      continue;
    }
    output << name_vec_.at(n) << "->" << name_vec_.at(i) << ": " << dist.at(i) << ", Path: ";
    printPath(paths, i, output);
    output << std::endl;
  }
  output << std::endl;
}

void Graph::DijkstraForBC(int n) {
  // priority queue min heap
  std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>> , std::greater<std::pair<double, int>>> pq;
  // to store the paths
  std::vector<int> paths(num_nodes_, -1);
  // distances from n
  std::vector<double> dist(num_nodes_, INT_MAX);
  
  // push n onto priority q with distance 0
  pq.push(std::make_pair(0, n));
  dist.at(n) = 0;
  
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    // for all nodes that u points to
    for (size_t i = 0; i < adj_matrix_.at(u).size(); ++i) {
      if (adj_matrix_.at(u).at(i)) {
        double weight = adj_matrix_.at(u).at(i)->getWeight();
        // if there is shortest path to from u to i
        if (dist.at(i) > dist.at(u) + weight) {
          dist.at(i) = dist.at(u) + weight;
          pq.push(std::make_pair(dist.at(i), i));
          paths.at(i) = u;
        }
      }
    }
  }
  // print result
  std::vector<int> row;
  for (size_t i = 0; i < num_nodes_; ++i) {
    if (dist.at(i) == INT_MAX) {
      continue;
    }
    addPath(paths, i, row);
    paths_.push_back(row);
  }
}

void Graph::printPath(std::vector<int>& parent, int j, std::ofstream& output) {
  if (parent.at(j) == - 1)
    return;
  printPath(parent, parent.at(j), output);
  output << name_vec_.at(j) << " ";
}

void Graph::addPath(std::vector<int>& parent, int j, std::vector<int>& new_vec) {
  while(parent.at(j) != - 1) {
    new_vec.push_back(j);
    j = parent.at(j);
  }
}

int Graph::NameToIdx(std::string name) const {
  for (int i = 0; i < name_vec_.size(); ++i) {
    if (name.compare(name_vec_.at(i)) == 0) {
      return i;
    }
  }
  return -1;
}
