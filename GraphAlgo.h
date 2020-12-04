/**
 * @file Algorithms.h
 * CS 225: Data Structures
 */


#pragma once

#include <vector>
#include <algorithm>

#include "graph.h"
#include "edge.h"
#include "GraphCreator.h"
#include "BFS.h"

#include <queue>

using namespace std;

class GraphAlgo {
public:

    GraphAlgo(GraphCreator G);

    private:
        GraphCreator gc;
        queue<Vertex> bfsTrav;
        map<Vertex> visitedNodes;
        Vertex startingVertex_;


};