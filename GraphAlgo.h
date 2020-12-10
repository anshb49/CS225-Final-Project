/**
 * @file GraphAlgo.h
 * CS 225: Data Structures
 */


#pragma once

#include <vector>
#include <algorithm>
#include <map>

#include "graph.h"
//#include "edge.h"
#include "interpretgraph.h"
// #include "BFS.h"

#include <queue>

using namespace std;

class GraphAlgo {
public:

    GraphAlgo(Graph G);
    tuple<vector<Vertex>, int> DijkstraAlgo(Graph g, Vertex source, Vertex destination);
    vector<Vertex> A_Star(Graph g, Vertex source, Vertex destination);
    int heuristic_fcn(Vertex start, Vertex dest);
    


    private:
        //GraphInitializer gc;
        queue<Vertex> bfsTrav;
        std::map<Vertex, bool> visitedNodes;
        Vertex startingVertex_;
        Graph g;

        


};