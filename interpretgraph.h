
#pragma once

#include <vector>
#include <algorithm>
#include <map>

#include "graph.h"
#include "edge.h"

/**
 * Represents a algorithm to create a Graph based on input vectors.
 */
class GraphInitializer {
public:

  GraphInitializer(std::vector<std::vector<std::string>> feat_vec, std::vector<std::vector<std::string>> edge_vec);
  

  /**
   * Returns a constant reference to the state space graph.
   *
   * @returns A constant reference to the state space graph.
   */
  const Graph & getGraph() const;
  const std::map<string, std::vector<string>> & getFeaturesMap() const;

private:
  Graph g_;
  Vertex startingVertex_;
  std::vector<std::vector<std::string>> currentfeatures_vec;
  std::vector<std::vector<std::string>> currentedges_vec;

  std::map<string, std::vector<string>> featuresMAP;
};