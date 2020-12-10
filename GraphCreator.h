/**
 * @file GraphCreator.h
 */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include "graph.h"
#include "edge.h"


class GraphCreator {
public:

  GraphCreator();

  GraphCreator(std::vector<std::vector<std::string>> feat_vec, std::vector<std::vector<std::string>> edge_vec);

  /**
   * Label the edges as "WIN" or "LOSE" based on a threshold.
   */
  //Do we need this??
  //void labelEdgesFromThreshold(int threshold);

  /**
   * Returns a constant reference to the state space graph.
   *
   * @returns A constant reference to the state space graph.
   */
  const Graph & getGraph() const;

private:
  Graph g_;
  Vertex startingVertex_;
  int num_tokens = 0;
  std::vector<std::vector<std::string>> currentfeatures_vec;
  std::vector<std::vector<std::string>> currentedges_vec;
};