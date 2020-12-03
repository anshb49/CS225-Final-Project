/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#include "GraphCreator.h"
#include <ctime>
#include <map>

using namespace std;

/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
GraphCreator::GraphCreator(std::vector<std::vector<std::string>> feat_vec, std::vector<std::vector<std::string>> edge_vec) : g_(true, true) {
    /* Your code goes here! */

    currentfeatures_vec = feat_vec;
    currentedges_vec = edge_vec;

    std::map<string, std::vector<string>> graph_map;

    //Create map containing features with key as newID and value as vector of features
    for (int i = 0; i < currentfeatures_vec.size(); i++) {
        graph_map[currentfeatures_vec[i][5]] = currentfeatures_vec[i];
    }

    //Create vertices for FROM values in edges file
    string previousID = ",";
    for (int i = 0; i < currentedges_vec.size(); i++) {
        if (previousID == currentedges_vec[i].at(0)) {
            continue;
        }
        Vertex v1 = currentedges_vec[i].at(0);
        g_.insertVertex(v1);
        previousID = currentedges_vec[i].at(0);
    }

    for (int i = 0; i < currentedges_vec.size(); i++) {
        string from_edge = currentedges_vec[i].at(0);
        string to_edge = currentedges_vec[i].at(1);

        g_.insertEdge(from_edge, to_edge);
        g_.setEdgeWeight(from_edge, to_edge, stoi(graph_map[to_edge].at(3)));
    }

    /*
    for (int i = 0; i <= (int)startingTokens; i++) {
      string p1 = "p1-" + std::to_string(startingTokens - i);
      string p2 = "p2-" + std::to_string(startingTokens - i);
      g_.insertVertex(Vertex(p1));
      g_.insertVertex(Vertex(p2));
    }

    for (int i = 0; i < (int)startingTokens; i++) {

      string p2_edge = "p2-" + std::to_string(startingTokens - i);
      string p1_edge = "p1-" + std::to_string(startingTokens - i);


      if (startingTokens - i - 1 >= 0 && startingTokens - i - 1 <= startingTokens) {
        string p2_edge1 = "p2-" + std::to_string(startingTokens - i - 1);
        g_.insertEdge(Vertex(p1_edge), Vertex(p2_edge1));
        g_.setEdgeWeight(Vertex(p1_edge), Vertex(p2_edge1), 0);
      }

      if (startingTokens - i - 2 >= 0 && startingTokens - i - 2 <= startingTokens) {
        string p2_edge2 = "p2-" + std::to_string(startingTokens - i - 2);
        g_.insertEdge(Vertex(p1_edge), Vertex(p2_edge2));
        g_.setEdgeWeight(Vertex(p1_edge), Vertex(p2_edge2), 0);
      }


      

      if (startingTokens - i - 1 >= 0 && startingTokens - i - 1 <= startingTokens) {
        string p1_edge1 = "p1-" + std::to_string(startingTokens - i - 1);
        g_.insertEdge(Vertex(p2_edge), Vertex(p1_edge1));
        g_.setEdgeWeight(Vertex(p2_edge), Vertex(p1_edge1), 0);
      }

      if (startingTokens - i - 2 >= 0 && startingTokens - i - 2 <= startingTokens) {
        string p1_edge2 = "p1-" + std::to_string(startingTokens - i - 2);
        g_.insertEdge(Vertex(p2_edge), Vertex(p1_edge2));
        g_.setEdgeWeight(Vertex(p2_edge), Vertex(p1_edge2), 0);
      }
      */
      
    }
}

/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const {
  vector<Edge> path;
  /* Your code goes here! */
  string temp_stirng = "p1-" + std::to_string(num_tokens);
  bool isPlayer1Turn = false;
  Vertex currentVertex = Vertex(temp_stirng);
  isPlayer1Turn = true;

  if (num_tokens == 0 || num_tokens == 1 || num_tokens == 2) {
    //path.push_back(g_.getEdge())
  }

  int num_left = num_tokens;

  for (int i = num_tokens; i >= 0; i--) {
    
    if (num_left == 0) {
      break;
    } else {
      Vertex output;
      vector<Vertex> current_vertexes = g_.getAdjacent(currentVertex);

      int decider = rand() % 1;

      if (current_vertexes.size() == 0) {
        break;
      }


      output = current_vertexes.at(decider);
      Edge temp = g_.getEdge(currentVertex, output);
      path.push_back(temp);
      

      if (decider == 0) {
        //path.push_back(current_edges[0]);
      } else if (decider == 1) {
        //path.push_back(current_edges[1]);
      }
      currentVertex = output;
      

      int p2_amount = rand() % num_tokens;
      p2_amount++;
    }


  }
  return path;
}

/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path) {
 /* Your code goes here! */
  int player_w = 1;
  int player_id = 2;
  string losing_player = path.at(path.size() - 1).source.substr(0, player_id);
  bool isPlayer1 = false;
  bool isPlayer2 = false;
  losing_player = losing_player.substr(0, 2);

  if ("p1" == path[path.size() - 1].dest) {
    player_w = -1;
  }

  //std::cout << "answer: " << losing_player;
    
    for (int i = 0; i < (int)path.size(); i = i + 1) {
      Edge current_move = path[i];

      string current_play = current_move.source;


      if (losing_player == "p1" && current_play.substr(0, 2) == "p1") {
        int new_weight = current_move.getWeight() + 1; 
        isPlayer1 = true;
        g_.setEdgeWeight(current_move.source, current_move.dest, new_weight);

      } else if (losing_player == "p1" && current_play.substr(0, 2) == "p2") {
        int new_weight = current_move.getWeight() - 1; 
        isPlayer1 = true;
        g_.setEdgeWeight(current_move.source, current_move.dest, new_weight);
        
      } else if (losing_player == "p2" && current_play.substr(0, 2) == "p2") {
        int new_weight = current_move.getWeight() + 1; 
        isPlayer2 = true;
        g_.setEdgeWeight(current_move.source, current_move.dest, new_weight);

      } else if (losing_player == "p2" && current_play.substr(0, 2) == "p1") {
        int new_weight = current_move.getWeight() - 1; 
        isPlayer2 = true;
        g_.setEdgeWeight(current_move.source, current_move.dest, new_weight);
      }

    }
  } 



/**
 * Label the edges as "WIN" or "LOSE" based on a threshold.
 */
void NimLearner::labelEdgesFromThreshold(int threshold) {
  for (const Vertex & v : g_.getVertices()) {
    for (const Vertex & w : g_.getAdjacent(v)) {
      int weight = g_.getEdgeWeight(v, w);

      // Label all edges with positve weights as "WINPATH"
      if (weight > threshold)           { g_.setEdgeLabel(v, w, "WIN"); }
      else if (weight < -1 * threshold) { g_.setEdgeLabel(v, w, "LOSE"); }
    }
  }
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const {
  return g_;
}