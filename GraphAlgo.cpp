/**
GraphAlgo.cpp
*/

#include "GraphAlgo.h"



GraphAlgo::GraphAlgo(Graph g_) {
  g = g_;
  startingVertex_ = g_.getStartingVertex();
}

tuple<vector<Vertex>, int> GraphAlgo::DijkstraAlgo(Graph g, Vertex source, Vertex destination){
  // initialize distances  // initialize tentative distance value
  // initialize previous   // initialize a map that maps current node -> its previous node
  // initialize priority_queue   // initialize the priority queue
  // initialize visited

  // while the top of priority_queue is not destination:
  //     get the current_node from priority_queue
  //     for neighbor in current_node's neighbors and not in visited:
  //         if update its neighbor's distances:
  //             previous[neighbor] = current_node
  //     save current_node into visited

  // extract path from previous
  // return path and distance

  std::map<Vertex, int> distance_djikstra;
  std::map<Vertex, Vertex> previous_node;

  for (Vertex v : g.getVertices()) {
    distance_djikstra[v] = INT_MAX; //infinite;
    previous_node[v] = "";
  }
  distance_djikstra[source] = 0;
  
  priority_queue<Vertex> p_queue;
  for (int i = 0; i < (int)g.getVertices().size(); i++) {
    p_queue.push(g.getVertices().at(i));
  }

  Vertex current_node;
  while (p_queue.empty() == false) {
    current_node = p_queue.top();
    p_queue.pop();

    for (Vertex v : g.getAdjacent(current_node)) {
      Edge e;
      if (g.edgeExists(current_node, v)) {
        e = g.getEdge(current_node, v);
      } else {
        e = g.getEdge(v, current_node);
      }

      int cost = e.getWeight();
      if (cost + distance_djikstra[current_node] < distance_djikstra[v]) {
        distance_djikstra[v] = cost + distance_djikstra[current_node];
        previous_node[v] = current_node;
      }
    }
  
  }

  vector<Vertex> path;
  Vertex last_node = current_node;
  int distance = distance_djikstra[last_node];
  while (last_node != source) {
    /* code */
    Vertex p = previous_node[last_node];
    path.push_back(p);
    //distance +=
  }

  tuple<vector<Vertex>, int> output_vals = make_tuple(path, distance);
  return output_vals;
}


vector<Vertex> GraphAlgo::A_Star(Graph g, Vertex source, Vertex destination){
  priority_queue<Vertex> discovered_nodes;
  std::map<Vertex, Vertex> previous_node;

  std::map<Vertex, int> gScore_values;
  gScore_values[source] = 0;

  std::map<Vertex, int> fScore_values;
  fScore_values[source] = heuristic_fcn(source, destination);

  while (discovered_nodes.empty() == false) {
    Vertex current_node = discovered_nodes.top();
    discovered_nodes.pop();

    if (current_node == destination) {
      //Finish this
    }

    for (Vertex v : g.getAdjacent(current_node)) {
    
      int temp_gScore = gScore_values[current_node] + g.getEdgeWeight(current_node, v);
      if (temp_gScore < gScore_values[v]) {
        previous_node[v] = current_node;
        gScore_values[v] = temp_gScore;
        fScore_values[v] = gScore_values[v] + heuristic_fcn(v, destination);

        /*
        for (int i = 0; i < (int)discovered_nodes.size(); i++) {
          
        }
        */
      }
    }


  }
  vector<Vertex> out;
  return out;
}



int GraphAlgo::heuristic_fcn(Vertex start, Vertex dest) {
  return get<1>(DijkstraAlgo(g, start, dest));
}

