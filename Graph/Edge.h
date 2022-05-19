#pragma once
#include "Node.h"

class Edge {
 public:
 
 /**
  * @param from Node* that the edge is pointing from
  * @param to Node* that the edge is pointing to
  */
  Edge(const Node* from, const Node* to) : from_(from), to_(to) {}
  
  /**
  * @return the weight of the origin node of an edge
  * 
  */
  double getWeight() const { return from_->getWeight(); }

  /**
  * @return the destination  node of an edge
  */
  const Node* getDest() const { return to_; }

  /**
  * @return the origin node of an edge
  */
  const Node* getOrigin() const { return from_; }

 private:
  const Node* from_;
  const Node* to_;
};