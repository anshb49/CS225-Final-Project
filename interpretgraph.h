/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#pragma once

#include <vector>
#include <algorithm>
#include <map>

#include "graph.h"
#include "edge.h"

/**
 * Represents a algorithm to learn the game of Nim.
 */
class GraphInitializer {
public:

  GraphInitializer(std::vector<std::vector<std::string>> feat_vec, std::vector<std::vector<std::string>> edge_vec);
  

  /*
   * Updates the edge weights on the graph based on a path through the state
   * tree.
   *
   * If the `path` has Player 1 winning (eg: the last vertex in the path goes
   * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
   * took the last token), then all choices made by Player 1 (edges where
   * Player 1 is the source vertex) are rewarded by increasing the edge weight
   * by 1 and all choices made by Player 2 are punished by changing the edge
   * weight by -1.
   *
   * Likewise, if the `path` has Player 2 winning, Player 2 choices are
   * rewarded and Player 1 choices are punished.
   *
   * @param path A path through the a game of Nim to learn.
   */
  void updateEdgeWeights(const std::vector<Edge> & path);

  /**
   * Label the edges as "WIN" or "LOSE" based on a threshold.
   */
  void labelEdgesFromThreshold(int threshold);

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
  int num_tokens = 0;
  std::vector<std::vector<std::string>> currentfeatures_vec;
  std::vector<std::vector<std::string>> currentedges_vec;

  std::map<string, std::vector<string>> featuresMAP;
};