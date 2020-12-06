
#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "BFS.h"

BFS::BFS(Vertex & start, Graph graph_trav){
  start_vertex = start;
  g = graph_trav;
  bfs.push(start_vertex);
}


BFS::Iterator::Iterator() {
    //EMPTY
}

BFS::Iterator::Iterator(Vertex & start, Graph graph_trav) {
  startVertex = start;
  g = graph_trav;

  currentVertex = trav->peek();
  //ADD VISISTED NOTES
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
BFS::Iterator & BFS::Iterator::operator++() {
  if(trav->empty()){
    return *this;
  }
  for(int i = 0; i < this->)
    // Setup
// Maintain a queue
// Maintain a table of vertices with following features:
// Boolean flag - visited
// Distance from the start
// Predecessor
// List of adjacent vertices

// Algorithm:
// Add the starting point
// While the queue is not empty
// Dequeue v
// For all of the unlabeled edges adjacent to v
// If an adjacent edge “discovers” a new vertex t:
// Label the edge a “discovery edge”
// Enqueue t, update the information of t (distance = dist(v) + 1, predecessor = v)
// If an adjacent edge is between two visited vertices
// Label the edge a “cross edge”

// BFSTraversal(start_node):
//   visited := a set to store references to all visited nodes

//   queue := a queue to store references to nodes we should visit later
//   queue.enqueue(start_node)
//   visited.add(start_node)

//   while queue is not empty:
//     current_node := queue.dequeue()

//     process current_node
//     # for example, print(current_node.value)

//     for neighbor in current_node.neighbors:
//       if neighbor is not in visited:
//         queue.enqueue(neighbor)
//         visited.add(neighbor)
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the BFS.
 */
Vertex BFS::Iterator::operator*() {
  
  return currentVertex;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool BFS::Iterator::operator!=(const BFS::Iterator &other) {
  

  if (trav == NULL || trav -> empty() == true) {
    if (other.trav == NULL || other.trav->empty() == true) {
      return false;
    }
  } 
  return true;

}

BFS::Iterator BFS::begin() {
  
  return BFS::Iterator(start_vertex, g);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
BFS::Iterator BFS::end() {
  
  return BFS::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Vertex & v) {
  
  bfs.push(v);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Vertex BFS::pop() {
  
  Vertex ret = bfs.front();
  bfs.pop();
  return ret;
}

/**
 * Returns the current Point in the traversal.
 */
Vertex BFS::peek() const {
  
  Vertex ret = bfs.front();
  return ret;
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  
  if (bfs.empty()) {
    return true;
  }
  return false;
}