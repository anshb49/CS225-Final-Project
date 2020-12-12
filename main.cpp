#include <iostream>
#include <vector>
#include "parser.h"
#include "GraphAlgo.h"
//#include "graphcreator.h"
#include "interpretgraph.h"


int main(int argc, const char * argv[]) {
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	std::cout << "Filename: " << argv[1] << std::endl;

	cout << "" << endl;
	cout << "" << endl;

	//std::cout << "Vector Representation:" << std::endl;
	std::string fileTarget = argv[1];

	//std::vector<std::string> vectorRepr = file_to_vector("musae_"+fileTarget+"_target.csv");

	std::vector<std::vector<std::string>> data_vector = file_to_data("musae_"+fileTarget+"_target.csv"); //MAYBE USE PARSER::?
	
	std::vector<std::vector<std::string>> edgesVec = file_to_edges("musae_"+fileTarget+"_edges.csv"); //MAYBE USE PARSER::?;
	
	GraphInitializer gc(data_vector, edgesVec);
	Graph testGraph = gc.getGraph();

	
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();
	vector<int> BFS_output = testGraph.BFS(testGraph.getStartingVertex(), feat_map); //Create Presenation for BFS output
	std::cout << printBFSOutput(BFS_output) << std::endl;

	cout << "" << endl;
	cout << "" << endl;
	Vertex startVertex;
	Vertex destVertex;

	startVertex = testGraph.getVertices().at(218);
	destVertex = testGraph.getVertices().at(230);
	
	GraphAlgo ga(testGraph);
	std::cout << "Dijkstra Source: " << feat_map[startVertex].at(5) << std::endl;
	std::cout << "Dijkstra Destination: " << feat_map[destVertex].at(5) << std::endl;
	tuple<vector<Vertex>, int> djikstra_output = ga.DijkstraAlgo(testGraph, startVertex, destVertex);
	std::cout << "Dijkstra: " << get<1>(djikstra_output) << std::endl;
	vector<Vertex> pathway = get<0>(djikstra_output);
	reverse(pathway.begin(), pathway.end());

	vector<vector<std::string>> dijk_data;

	cout << "Dijkstra Path: ";
	for (Vertex v: pathway) {
		dijk_data.push_back(feat_map[v]);
		cout<< v << " ";
	}
	cout <<"" <<endl;

	double total_views_dijk = 0;
	double total_days_dijk = 0;
	for (vector<string> current : dijk_data) {
		for (string s : current) {
			cout << s << " ";
		}
		total_views_dijk += stoi(current.at(3));
		total_days_dijk += stoi(current.at(1));
		cout << "" << std::endl;
	}

	double avg_views_dijk = total_views_dijk / dijk_data.size();
	double avg_days_dijk = total_days_dijk / dijk_data.size();
	std::cout << "Dijkstra Average Views: " << avg_views_dijk << std::endl;
	std::cout << "Dijkstra Average Days on Account: " << avg_days_dijk << std::endl;

	cout << "" << endl;
	cout << "" << endl;
	

	vector<Vertex> a_output = ga.A_Star(testGraph, startVertex, destVertex);
	std::cout << "A* Source: " << feat_map[startVertex].at(5) << std::endl;
	std::cout << "A* Destination: " << feat_map[destVertex].at(5) << std::endl;
	reverse(a_output.begin(), a_output.end());
	vector<vector<std::string>> astar_data;
	cout<< "A* Path: ";
	for (Vertex v: a_output) {
		astar_data.push_back(feat_map[v]);
		cout << v << " ";
	}
	cout << "" << endl;

	

	double total_views_astar = 0;
	double total_days_astar = 0;
	for (vector<string> current : astar_data) {
		for (string s : current) {
			cout << s << " ";
		}
		total_views_astar += stoi(current.at(3));
		total_days_astar += stoi(current.at(1));
		cout << "" << std::endl;
	}	

	double avg_views_astar = total_views_astar / dijk_data.size();
	double avg_days_astar = total_days_astar / dijk_data.size();
	std::cout << "A* Algorithm Average Views: " << avg_views_astar << std::endl;
	std::cout << "A* Algorithm Average Days on Account: " << avg_days_astar << std::endl;

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	
}