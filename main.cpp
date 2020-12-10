#include <iostream>
#include <vector>
#include "parser.h"
#include "GraphAlgo.h"
//#include "graphcreator.h"
#include "interpretgraph.h"


int main(int argc, const char * argv[]) {
	std::cout << "Filename: " << argv[1] << std::endl;
	
	// convert file to string representation
	std::cout << "String Representation:" << std::endl;
	//std::cout << file_to_string(argv[1]) << std::endl;
	
	// convert file to vector representation

	

	std::cout << "Vector Representation:" << std::endl;
	std::string fileTarget = argv[1];

	//std::vector<std::string> vectorRepr = file_to_vector("musae_"+fileTarget+"_target.csv");

	std::vector<std::vector<std::string>> data_vector = file_to_data("musae_"+fileTarget+"_target.csv"); //MAYBE USE PARSER::?

	// std::cout<<data_vector[15].at(5) << std::endl; // testcase
	// std::cout<<data_vector[34].at(5)<< std::endl;// testcase
	// std::cout<<data_vector[89].at(5)<< std::endl;// testcase
	
	std::vector<std::vector<std::string>> edgesVec = file_to_edges("musae_"+fileTarget+"_edges.csv"); //MAYBE USE PARSER::?;
	// std::cout<<edgesVec[1].at(0)<< std::endl;// testcase
	// std::cout<<edgesVec[1].at(1)<< std::endl;// testcase
	
	GraphInitializer gc(data_vector, edgesVec);
	Graph testGraph = gc.getGraph();

	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();
	vector<int> BFS_output = testGraph.BFS(testGraph.getVertices().at(0), feat_map); //Create Presenation for BFS output
	for (int i = 0; i < (int)BFS_output.size(); i++) {
		std::cout << BFS_output[i] << std::endl;
	}

	GraphAlgo ga(testGraph);
	tuple<vector<Vertex>, int> djikstra_output = ga.DijkstraAlgo(testGraph, testGraph.getStartingVertex(), testGraph.getVertices().at(50));
	std::cout << "Djikstra Source: " << feat_map[testGraph.getStartingVertex()].at(5) << std::endl;
	std::cout << "Djikstra Destination: " << feat_map[testGraph.getVertices().at(50)].at(5) << std::endl;
	std::cout << "Djikstra: " << get<1>(djikstra_output) << std::endl;
	//GraphCreator gc(data_vector, edgesVec);
	//GraphCreator gc = GraphCreator(data_vector, edgesVec);
	//Graph &g = gc.getGraph();

	//Psuedocode for Graph
	//Parse through edges file to create 2d matrix using similar code from above
	//parse all these column values as ints and use sorting algorithm 
		//possibly use binary serach or another search algorithm to improve efficiency
	//Create new vertex based on "from" value using all its information
	//create second vertex based on "to" value using its info
	//Use graph class to create edges between first column to second column from edges matrix

}