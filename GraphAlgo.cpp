/**
Algorithms.cpp
*/



/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this BFS is going to traverse
 * @param start The start point of this BFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this BFS
 */
GraphAlgo::GraphAlgo(Graph g) {
  startingVertex_ = g.getStartingVertex();
  GraphCreator gc = new GraphCreator()
  visitedNodes = BFS::BFS(g);
}