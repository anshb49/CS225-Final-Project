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
                Iterator(Vertex & start, Graph graph_trav);
                Iterator & operator++();
                Vertex operator*();
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
    BFS(Vertex & start, Graph graph_trav);

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
    Vertex peek() const;

    /**
    * To see if the traversal has no points left
    * 
    */
    bool empty() const;
    private:
        Graph g;             //extra graph g???
        // std::vector<std::vector<std::string>> feat_vec; 
        // std::vector<std::vector<std::string>> edge_vec;
        std::queue<Vertex> bfs;
        Vertex start_vertex;
}