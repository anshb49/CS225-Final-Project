/**
 * @file GraphAlgo.h
 * CS 225: Data Structures
 */

#pragma once

#include <vector>
#include <algorithm>
#include <map>

#include "graph.h"
#include "interpretgraph.h"

#include <queue>

using namespace std;

class GraphAlgo {
public:
    /**
     * Constructor for GraphAlgo class to set priavate variable graph.
     * @param - G is passed in graph to graph algorithm constructor
    */
    GraphAlgo(Graph G);

    /**
     * Performs Dijsktra Algorithm to find shortest distance from source to destination.
     * @param - g is passed in graph to graph algorithm constructor
     * @param - source is the input starting vertex for algorithm
     * @param - destination is the destination for path found
     * @return - a tuple containing path of the algorithm and the distance value
    */
    tuple<vector<Vertex>, int> DijkstraAlgo(Graph g, Vertex source, Vertex destination);

    /**
     * Performs A* Algorithm to find shortest distance from source to destination.
     * @param - g is passed in graph to graph algorithm constructor
     * @param - source is the input starting vertex for algorithm
     * @param - destination is the destination for path found
     * @return - a vector containing path of the algorithm
    */
    vector<Vertex> A_Star(Graph g, Vertex source, Vertex destination);

    /**
     * Contains heuristic function that is called in A* algorithm
     * @param - start is the input starting vertex for algorithm
     * @param - dest is the destination for path found
     * @return - an integer value for what was calculated in the function 
    */
    int heuristic_fcn(Vertex start, Vertex dest);
    


    private:
        std::map<Vertex, bool> visitedNodes; //keeps track of which vertices were visited
        Vertex startingVertex_; //initial starting vertex found from what was passed in constructor
        Graph g; //private variable for graph

        


};