/**
GraphAlgo.cpp
*/

#include "GraphAlgo.h"



GraphAlgo::GraphAlgo(Graph g_) {
  g = g_;
  startingVertex_ = g_.getStartingVertex();
}

tuple<vector<Vertex>, int> GraphAlgo::DijkstraAlgo(Graph g, Vertex source, Vertex destination){

  std::map<Vertex, int> distance_djikstra;
  std::map<Vertex, Vertex> previous_node;

  //initialized map values to infinite and set distance at the source to 0
  for (Vertex v : g.getVertices()) {
    distance_djikstra[v] = INT_MAX; //infinite;
    previous_node[v] = "test";
  }
  distance_djikstra[source] = 0;
  
  //Initialize priority queue and push in starting vertex
  priority_queue<pair<int, Vertex>, vector<pair<int, Vertex>>, std::greater<pair<int, Vertex>>> p_queue; //pair of distance and Vertex
  pair<int, Vertex> p= make_pair(0, source);
  p_queue.push(p);

  Vertex current_node;
  Vertex last_node = current_node;
  while (p_queue.empty() == false) {
    current_node = p_queue.top().second; //get top value off queue
    p_queue.pop();
    
    if (current_node == destination) { //leave method if destination is found
      break;
    }
    for (Vertex v : g.getAdjacent(current_node)) { //go through all adjacent edges
      Edge e;
      if (g.edgeExists(current_node, v)) {
        e = g.getEdge(current_node, v);
      } else {
        e = g.getEdge(v, current_node);
      }
      
      //perform correct weight calculation and set values in map 
      int cost = e.getWeight();
      if (cost + distance_djikstra[current_node] < distance_djikstra[v]) {
        distance_djikstra[v] = cost + distance_djikstra[current_node];
        
        previous_node[v] = current_node;

        int d = distance_djikstra[v];
        pair<int, Vertex> temp= make_pair(d, v);
        p_queue.push(temp); //push new value back into priority queue
      }
    }

  }
  vector<Vertex> path;
  last_node = current_node;
  int distance = distance_djikstra[last_node];

  if (last_node != destination) { //Case where destination was not found
    cout << "The chosen destination could not be found. This may be due to the starting and ending nodes being in different connected components" << endl;
    distance = -1;
  }

  path.push_back(last_node); //push back the last current vertex
  //continue while loop and keep pushing path vertices back until not "" or equal to source
  while (last_node != source && last_node != "") {
    Vertex p = previous_node[last_node];
    path.push_back(p);
    last_node = p;
  }
  
  //create a tuple of path of algorithm and distance for output
  tuple<vector<Vertex>, int> output_vals = make_tuple(path, distance);
  return output_vals;
}


vector<Vertex> GraphAlgo::A_Star(Graph g, Vertex source, Vertex destination){
  //initialize priority queue and push back the source
  priority_queue<pair<int, Vertex>, vector<pair<int, Vertex>>, std::greater<pair<int, Vertex>>> discovered_nodes; //pair of distance and Vertex
  pair<int, Vertex> p= make_pair(0, source);
  discovered_nodes.push(p);

  //create map for keeping track of previous nodes and map for weight values for main algorithm use
  std::map<Vertex, Vertex> previous_node;
  std::map<Vertex, int> gScore_values;
  std::map<Vertex, int> fScore_values;

  //Go through all vertices and set fscore and gscore map values to maximum
  for (Vertex v : g.getVertices()) {
    gScore_values[v] = INT_MAX;
    fScore_values[v] = INT_MAX;
  }
  gScore_values[source] = 0; //start gscore for source is 0
  fScore_values[source] = heuristic_fcn(source, destination); //call heuristic function for fscore start

  Vertex current_node; 
  //iterate through discovered nodes queue
  while (discovered_nodes.empty() == false) {
    current_node = discovered_nodes.top().second;
    discovered_nodes.pop();

    if (current_node == destination) {
      //Reached the destination
      break;
    }

    //go through all adjacent edges and add weight values to produce correct output path
    for (Vertex v : g.getAdjacent(current_node)) {
      int temp_gScore = gScore_values[current_node] + g.getEdgeWeight(current_node, v);
      if (temp_gScore < gScore_values[v]) { //if it is less then current gscore
        previous_node[v] = current_node;
        gScore_values[v] = temp_gScore;
        fScore_values[v] = gScore_values[v] + heuristic_fcn(v, destination); // call heuristic with current vertex and parameter destination

        int d = fScore_values[v];
        pair<int, Vertex> temp= make_pair(d, v);
        discovered_nodes.push(temp); //push new value back into the queue
      }
    }

  }

  
  vector<Vertex> path;
  Vertex last_node = current_node;

  if (last_node != destination) { //Case where destination does not exist
    cout << "The chosen destination could not be found. This may be due to the starting and ending nodes being in different connected components" << endl;
  }
  path.push_back(last_node);
  //Keep looping until path is created successfully
  while (last_node != source && last_node != "") {
    Vertex p = previous_node[last_node];
    path.push_back(p);
    last_node = p;
  }

  return path; //output path of shortest path between start and destination
}



int GraphAlgo::heuristic_fcn(Vertex start, Vertex dest) {
    Edge e;

    //Make sure that edge is existent and set current edge to that getEdge()
    if (g.edgeExists(start, dest)) {
      e = g.getEdge(start, dest);
    } else if (g.edgeExists(dest, start)) {
      e = g.getEdge(dest, start);
    } else {
      return 0;
    }
    
    //return weight value of the current edge that was found
    int cost = e.getWeight();
    return cost;
}

