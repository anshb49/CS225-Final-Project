#pragma once

#include <vector>
#include <algorithm>
#include <iterator>


#include "graph.h"
#include "edge.h"
#include "GraphCreator.h"
#include "BFS.h"

#include <queue>

class BFS {
    public:
        class Iterator : std::iterator<std::forward_iterator_tag, Vertex> {
            public:
                Iterator();
                Iterator(ImageTraversal * traversal, PNG & png, Point & start, double & tolerance);
                Iterator & operator++();
                Point operator*();
                bool operator!=(const Iterator &other);

                /** @todo [Part 1] */
                /** add member functions if neccesary*/

            private:
                /** @todo [Part 1] */
                /** add private members here if neccesary*/

                BFS * trav;
                std::vector<std::vector<bool>> visitedNodes;
                Vertex startVertex;
                Vertex currentVertex;
                Graph g;
        };

    /**
    * The begining of an iterator
    * 
    */
   Iterator begin();

    /**
    * The end of an iterator
    * 
    */
    Iterator end();

    /**
    * Add new point to the traversal
    * 
    */
    void add(const Vertex & v);
    /**
    * Remove and return the next point of the traversal
    * 
    */
    
    Vertex pop();
    /**
    * Return but not remove the next point of the traversal
    * 
    */
    Vertex peek();

    /**
    * To see if the traversal has no points left
    * 
    */
    bool empty();
    private:
        GraphCreator gc;
        Graph g;
        std::vector<std::vector<std::string>> feat_vec; 
        std::vector<std::vector<std::string>> edge_vec;
        queue<Vertex> bfs;
}