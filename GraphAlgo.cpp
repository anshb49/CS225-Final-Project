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
  
  priority_queue<pair<int, Vertex>, vector<pair<int, Vertex>>, std::greater<pair<int, Vertex>>> p_queue; //pair of distance and Vertex
  pair<int, Vertex> p= make_pair(0, source);
  p_queue.push(p);

  Vertex current_node;
  Vertex last_node = current_node;
  while (p_queue.empty() == false) {
    current_node = p_queue.top().second;
    p_queue.pop();
    
    if (current_node == destination) {
      break;
    }
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

        int d = distance_djikstra[v];
        pair<int, Vertex> temp= make_pair(d, v);
        p_queue.push(temp);
      }
    }

  }
  vector<Vertex> path;
  last_node = current_node;
  int distance = distance_djikstra[last_node];

  if (last_node != destination) {
    cout << "The chosen destination could not be found. This may be due to the starting and ending nodes being in different connected components" << endl;
    distance = -1;
  }

  path.push_back(last_node);
  while (last_node != source && last_node != "") {

    Vertex p = previous_node[last_node];

    path.push_back(p);
    last_node = p;
  }
  tuple<vector<Vertex>, int> output_vals = make_tuple(path, distance);
  return output_vals;
}


vector<Vertex> GraphAlgo::A_Star(Graph g, Vertex source, Vertex destination){
  priority_queue<pair<int, Vertex>, vector<pair<int, Vertex>>, std::greater<pair<int, Vertex>>> discovered_nodes; //pair of distance and Vertex
  pair<int, Vertex> p= make_pair(0, source);
  discovered_nodes.push(p);

  std::map<Vertex, Vertex> previous_node;

  std::map<Vertex, int> gScore_values;
  std::map<Vertex, int> fScore_values;
  for (Vertex v : g.getVertices()) {
    gScore_values[v] = INT_MAX;
    fScore_values[v] = INT_MAX;
  }
  gScore_values[source] = 0;
  fScore_values[source] = heuristic_fcn(source, destination);

  Vertex current_node;
  while (discovered_nodes.empty() == false) {
    current_node = discovered_nodes.top().second;
    discovered_nodes.pop();

    if (current_node == destination) {
      //Reached the destination
      break;
    }

    for (Vertex v : g.getAdjacent(current_node)) {
      int temp_gScore = gScore_values[current_node] + g.getEdgeWeight(current_node, v);
      if (temp_gScore < gScore_values[v]) {
        previous_node[v] = current_node;
        gScore_values[v] = temp_gScore;
        fScore_values[v] = gScore_values[v] + heuristic_fcn(v, destination);

        int d = fScore_values[v];
        pair<int, Vertex> temp= make_pair(d, v);
        discovered_nodes.push(temp);
      }
    }

  }

  
  vector<Vertex> path;
  Vertex last_node = current_node;

  if (last_node != destination) {
    cout << "The chosen destination could not be found. This may be due to the starting and ending nodes being in different connected components" << endl;
  }
  path.push_back(last_node);
  while (last_node != source && last_node != "") {
    Vertex p = previous_node[last_node];
    path.push_back(p);
    last_node = p;
  }

  return path;
}



int GraphAlgo::heuristic_fcn(Vertex start, Vertex dest) {
    Edge e;

    if (g.edgeExists(start, dest)) {
      e = g.getEdge(start, dest);
    } else if (g.edgeExists(dest, start)) {
      e = g.getEdge(dest, start);
    } else {
      return 0;
    }
      
    int cost = e.getWeight();
    return cost;
  //return get<1>(DijkstraAlgo(g, start, dest));
}

