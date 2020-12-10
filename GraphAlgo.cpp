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
    previous_node[v] = "test";
  }
  distance_djikstra[source] = 0;
  
  priority_queue<Vertex> p_queue;
  for (int i = 0; i < (int)g.getVertices().size() ; i++) {
    //std::cout << __LINE__ << std::endl;
    p_queue.push(g.getVertices().at(i));
  }
  std::cout << __LINE__ << std::endl;
  Vertex current_node;
  Vertex last_node = current_node;
  while (p_queue.empty() == false) {
    //std::cout << __LINE__ << std::endl;
    current_node = p_queue.top();
    p_queue.pop();

    //std::cout << __LINE__ << std::endl;
    std::cout << "current_node: "<< current_node << std::endl;
    //std::cout << "size: " << g.getAdjacent(current_node).size() << std::endl;
    
    for (Vertex v : g.getAdjacent(current_node)) {
      Edge e;
      std::cout << __LINE__ << std::endl;
      std::cout << v << std::endl;
      if (g.edgeExists(current_node, v)) {
        e = g.getEdge(current_node, v);
      } else {
        e = g.getEdge(v, current_node);
      }
      
      int cost = e.getWeight();
      std::cout << "cost: " << cost << std::endl;
      if (cost + distance_djikstra[current_node] < distance_djikstra[v]) {
        //std::cout << __LINE__ << std::endl;
        distance_djikstra[v] = cost + distance_djikstra[current_node];
        previous_node[v] = current_node;
        //std::cout << v << " " << current_node << "here" << std::endl;
      }
      std::cout << __LINE__ << std::endl;
      last_node = v;
    }

    std::cout << "empty> : " << p_queue.empty() << std::endl;
  }
  vector<Vertex> path;
  int distance = distance_djikstra[last_node];
  std::cout << previous_node[last_node] << " "<< source<< std::endl;
  std::cout << "distance: " << distance << std::endl;
  //int count = 0;
  while (last_node != source && last_node != "") {
    /* code */
    //std::cout << __LINE__ << std::endl;
    Vertex p = previous_node[last_node];
    //std::cout<< "Reached here" << previous_node[last_node] << std::endl;
    path.push_back(p);
    last_node = p;
    //distance +=
    //count++;
  }
  //std::cout << __LINE__ << std::endl;
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

