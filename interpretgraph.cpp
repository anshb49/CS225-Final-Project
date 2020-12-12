/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#include "interpretgraph.h"
#include <ctime>


GraphInitializer::GraphInitializer(std::vector<std::vector<std::string>> feat_vec, std::vector<std::vector<std::string>> edge_vec) : g_(true, true) {
    /* Your code goes here! */

    currentfeatures_vec = feat_vec;
    currentedges_vec = edge_vec;

    std::map<string, std::vector<string>> graph_map;

    std::map<Vertex, bool> visited;

    //Create map containing features with key as newID and value as vector of features
    for (int i = 0; i < (int)currentfeatures_vec.size(); i++) {
        graph_map[currentfeatures_vec[i][5]] = currentfeatures_vec[i];
        visited[currentfeatures_vec[i][5]] = false;
    }

    
    //Create vertices for FROM values in edges file
    for (int i = 0; i < (int)currentedges_vec.size(); i++) {
        Vertex v1 = currentedges_vec[i].at(0);
        if (visited[v1] == false) {
           g_.insertVertex(v1);
           visited[v1] = true;
        }
        Vertex v2 = currentedges_vec[i].at(1);
        if (visited[v2] == false) {
           g_.insertVertex(v2);
           visited[v2] = true;
        }
    }


    for (int i = 0; i < (int)currentedges_vec.size(); i++) {
        string from_edge = currentedges_vec[i].at(0);
        string to_edge = currentedges_vec[i].at(1);
        g_.insertEdge(from_edge, to_edge);
        g_.setEdgeWeight(from_edge, to_edge, stoi(graph_map[to_edge].at(3)));   //set edge weight to views
    } 

    featuresMAP = graph_map;
  }





/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & GraphInitializer::getGraph() const {
  return g_;
}


const std::map<string, std::vector<string>> & GraphInitializer::getFeaturesMap() const {
  return featuresMAP;
}