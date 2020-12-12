#include <iostream>
#include <vector>
#include "parser.h"
#include "GraphAlgo.h"
#include "interpretgraph.h"


int main(int argc, const char * argv[]) {
	//Inital format spacing
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	std::cout << "Filename: " << argv[1] << std::endl;

	cout << "" << endl;
	cout << "" << endl;

	std::string fileTarget = argv[1]; // Target file to run data on

	//Create vectors to store data and initialize graph
	std::vector<std::vector<std::string>> data_vector = file_to_data("musae_"+fileTarget+"_target.csv"); 
	std::vector<std::vector<std::string>> edgesVec = file_to_edges("musae_"+fileTarget+"_edges.csv"); 
	
	GraphInitializer gc(data_vector, edgesVec);
	Graph testGraph = gc.getGraph(); //Create graph for input

	//Get features values to run BFS algorithm on
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();
	vector<int> BFS_output = testGraph.BFS(testGraph.getStartingVertex(), feat_map);
	std::cout << printBFSOutput(BFS_output) << std::endl; //print out BFS traversal

	cout << "" << endl;
	cout << "" << endl;

	//Initialize start vertex and destination vertices to be passed in
	Vertex startVertex;
	Vertex destVertex;
	startVertex = testGraph.getVertices().at(218);
	destVertex = testGraph.getVertices().at(230);
	
	//Construct GraphAlgo
	GraphAlgo ga(testGraph);

	//Print basic info on source and destination
	std::cout << "Dijkstra Source: " << feat_map[startVertex].at(5) << std::endl;
	std::cout << "Dijkstra Destination: " << feat_map[destVertex].at(5) << std::endl;

	//Store output nad reverse output path for correct readable order
	tuple<vector<Vertex>, int> djikstra_output = ga.DijkstraAlgo(testGraph, startVertex, destVertex);
	std::cout << "Dijkstra: " << get<1>(djikstra_output) << std::endl;
	vector<Vertex> pathway = get<0>(djikstra_output);
	reverse(pathway.begin(), pathway.end());

	vector<vector<std::string>> dijk_data;
	//Print Dijkstra Path
	cout << "Dijkstra Path: ";
	for (Vertex v: pathway) {
		dijk_data.push_back(feat_map[v]);
		cout<< v << " ";
	}
	cout <<"" <<endl;

	//Calculate average number of views and days of account
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
	//print out average information
	double avg_views_dijk = total_views_dijk / dijk_data.size();
	double avg_days_dijk = total_days_dijk / dijk_data.size();
	std::cout << "Dijkstra Average Views: " << avg_views_dijk << std::endl;
	std::cout << "Dijkstra Average Days on Account: " << avg_days_dijk << std::endl;

	cout << "" << endl;
	cout << "" << endl;
	
	//Perform A* method and print basic information about source and destination
	vector<Vertex> a_output = ga.A_Star(testGraph, startVertex, destVertex);
	std::cout << "A* Source: " << feat_map[startVertex].at(5) << std::endl;
	std::cout << "A* Destination: " << feat_map[destVertex].at(5) << std::endl;

	//Reverse pathway for readablitiy
	reverse(a_output.begin(), a_output.end());

	//Print out A* path
	vector<vector<std::string>> astar_data;
	cout<< "A* Path: ";
	for (Vertex v: a_output) {
		astar_data.push_back(feat_map[v]);
		cout << v << " ";
	}
	cout << "" << endl;

	//Print out and calculate avergage views and days data point
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

	//print average information
	double avg_views_astar = total_views_astar / dijk_data.size();
	double avg_days_astar = total_days_astar / dijk_data.size();
	std::cout << "A* Algorithm Average Views: " << avg_views_astar << std::endl;
	std::cout << "A* Algorithm Average Days on Account: " << avg_days_astar << std::endl;

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	
}