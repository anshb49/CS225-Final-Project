/**
 * @file Algorithms.h
 * CS 225: Data Structures
 */


#pragma once

#include <vector>
#include <algorithm>
#include <map>

#include "graph.h"
#include "edge.h"
#include "GraphCreator.h"
#include "BFS.h"

#include <queue>

using namespace std;

class GraphAlgo {
public:

    GraphAlgo(Graph G);
    int DijkstraAlgo(Graph g, Vertex source, Vertex destination);


    private:
        GraphCreator gc;
        queue<Vertex> bfsTrav;
        std::map<Vertex> visitedNodes;
        Vertex startingVertex_;
        Graph g;


};