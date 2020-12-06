/**
Algorithms.cpp
*/

#include "GraphAlgo.h"



GraphAlgo::GraphAlgo(Graph g_) {
  g = g_;
  startingVertex_ = g_.getStartingVertex();
}

int GraphAlgo::DijkstraAlgo(Graph g, Vertex source, Vertex destination){
  // initialize distances  // initialize tentative distance value
  // initialize previous   // initialize a map that maps current node -> its previous node
  // initialize priority_queue   // initialize the priority queue
  // initialize visited

  // while the top of priority_queue is not destination:
  //     get the current_node from priority_queue
  //     for neighbor in current_node's neighbors and not in visited:
  //         if update its neighbor's distances:
  //             previous[neighbor] = current_node
  //     save current_node into visited

  // extract path from previous
  // return path and distance
}