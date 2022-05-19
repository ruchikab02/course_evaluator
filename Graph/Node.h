
#pragma once
#include <string>
#include <iostream>

class Node {
 public:
 /**
  * Node constructor
  * 
  * @param name Name of the node - in our case it is the name of the course
  * @param weight Weight of the node - in our case it is the gpa
  * @param index Index of the node in the adjacency matrix
  */
  Node(std::string name, double weight, size_t index): name_(name), weight_(weight), index_(index) {}
  
  /**
  * @return std::string name of the course
  */
  std::string getName() const { return name_; }

  /**
  * @return double weight of the course
  */
  double getWeight() const { return weight_; }

  /**
  * @return size_t the index of the node
  */
  size_t getIndex() const { return index_; }

  /**
  * @return true if a node is smaller than another node
  * Overloaded operator to help with other functions
  */
  bool operator<(const Node& right) const { return weight_ < right.weight_; }

  void print() const { std::cout << name_ << ": " << weight_ << std::endl; }
 
 private:
 /** Private Implementation: Each node stores the name, weight and index */
  std::string name_;
  double weight_;
  size_t index_;
};