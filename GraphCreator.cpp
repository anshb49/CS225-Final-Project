/**
 * @file GraphCreator.cpp
 */

#include "GraphCreator.h"
#include <ctime>
#include <map>

using namespace std;


GraphCreator::GraphCreator(std::vector<std::vector<std::string>> feat_vec, std::vector<std::vector<std::string>> edge_vec) : g_(true, true) {
    /* Your code goes here! */

    currentfeatures_vec = feat_vec;
    currentedges_vec = edge_vec;

    std::map<string, std::vector<string>> graph_map;

    //Create map containing features with key as newID and value as vector of features
    for (int i = 0; i < currentfeatures_vec.size(); i++) {
        graph_map[currentfeatures_vec[i][5]] = currentfeatures_vec[i];
    }

    //Create vertices for FROM values in edges file
    string previousID = ",";
    for (int i = 0; i < currentedges_vec.size(); i++) {
        if (previousID == currentedges_vec[i].at(0)) {
            continue;
        }
        Vertex v1 = currentedges_vec[i].at(0);
        g_.insertVertex(v1);
        previousID = currentedges_vec[i].at(0);
    }

    for (int i = 0; i < currentedges_vec.size(); i++) {
        string from_edge = currentedges_vec[i].at(0);
        string to_edge = currentedges_vec[i].at(1);

        g_.insertEdge(from_edge, to_edge);
        g_.setEdgeWeight(from_edge, to_edge, stoi(graph_map[to_edge].at(3)));   //set edge weight to views
    } 
  }


/**
 * Label the edges as "WIN" or "LOSE" based on a threshold.
 */
void NimLearner::labelEdgesFromThreshold(int threshold) {
  for (const Vertex & v : g_.getVertices()) {
    for (const Vertex & w : g_.getAdjacent(v)) {
      int weight = g_.getEdgeWeight(v, w);

      // Label all edges with positve weights as "WINPATH"
      if (weight > threshold)           { g_.setEdgeLabel(v, w, "WIN"); }
      else if (weight < -1 * threshold) { g_.setEdgeLabel(v, w, "LOSE"); }
    }
  }
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & GraphCreator::getGraph() const {
  return g_;
}