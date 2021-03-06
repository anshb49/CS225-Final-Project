#include <string>
#include <vector>

#include "../cs225/catch/catch.hpp"
#include "../parser.h"
#include "../interpretgraph.h"
#include "../GraphAlgo.h"

std::vector<std::vector<std::string>> data_vector = file_to_data("musae_ES_target.csv"); 
std::vector<std::vector<std::string>> edgesVec = file_to_edges("musae_ES_edges.csv"); 

std::vector<std::vector<std::string>> data_vector_SMALL = file_to_edges("musae_TEST_target.csv"); 
std::vector<std::vector<std::string>> edgesVec_SMALL = file_to_edges("musae_TEST_edges.csv"); 



TEST_CASE("Verify parsing data vector values are accurate - Small Sample") {
    std::vector<std::vector<std::string>> data_vector = file_to_data("musae_TEST_target.csv");
	REQUIRE(data_vector[2].at(5) == "220");
    REQUIRE(data_vector[4].at(5) == "60");
}

TEST_CASE("Verify parsing data vector values are accurate - Large Sample") {
    std::vector<std::vector<std::string>> data_vector = file_to_data("musae_ES_target.csv");
	REQUIRE(data_vector[14].at(5) == "4123");
    REQUIRE(data_vector[33].at(5) == "3320");
    REQUIRE(data_vector[88].at(5) == "208");
}

TEST_CASE("Verify parsing edges vector values are accurate - Small Sample") {
	std::vector<std::vector<std::string>> edgesVec = file_to_edges("musae_TEST_edges.csv"); 
    REQUIRE(edgesVec[1].at(1) == "220");
	REQUIRE(edgesVec[3].at(1) == "1170");
}

TEST_CASE("Verify parsing edges vector values are accurate - Large Sample") {
	std::vector<std::vector<std::string>> edgesVec = file_to_edges("musae_ES_edges.csv"); 
    REQUIRE(edgesVec[0].at(1) == "1819");
	REQUIRE(edgesVec[23].at(0) == "3");
    REQUIRE(edgesVec[617].at(1) == "1985");
}


TEST_CASE("Verify BFS output string is accurate") {
	vector<int> sampleBFSout;
	sampleBFSout.push_back(297);
	sampleBFSout.push_back(1411);
	sampleBFSout.push_back(693);
	sampleBFSout.push_back(126);
	sampleBFSout.push_back(267);
	sampleBFSout.push_back(2794);

	std::string correct_string = "0 - 1000 Views: 297 ||  1000 - 10000 Views: 1411 ||  10001 - 50000 Views: 693 ||  50001 - 100000 Views: 126 ||  Over 100000 Views: 267 ||  Total Vertices: 2794 || ";

    REQUIRE(printBFSOutput(sampleBFSout) == correct_string);
}

TEST_CASE("Verify that the Graph is initialized correctly - Small Sample") {
	GraphInitializer gc(data_vector_SMALL, edgesVec_SMALL);
	Graph outputGraph = gc.getGraph(); 
	
    REQUIRE(outputGraph.getStartingVertex() == "1170");
	REQUIRE(outputGraph.getEdges().size() == 15);
	REQUIRE(outputGraph.getVertices().size() == 14);
}

TEST_CASE("Verify that the Graph is initialized correctly - Large Sample") {
	GraphInitializer gc(data_vector, edgesVec);
	Graph outputGraph = gc.getGraph(); 
	
    REQUIRE(outputGraph.getStartingVertex() == "217");
	REQUIRE(outputGraph.getEdges().size() == 59382);
	REQUIRE(outputGraph.getVertices().size() == 4648);
}

TEST_CASE("Verify that the Graph BFS Algorithm - Small Sample") {
	GraphInitializer gc(data_vector_SMALL, edgesVec_SMALL);
	Graph outputGraph = gc.getGraph(); 

	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();
	vector<int> BFS_output = outputGraph.BFS(outputGraph.getVertices().at(0), feat_map);

	vector<int> correct_vector;
	correct_vector.push_back(1);
	correct_vector.push_back(8);
	correct_vector.push_back(3);
	correct_vector.push_back(1);
	correct_vector.push_back(1);
	correct_vector.push_back(14);
    REQUIRE(BFS_output == correct_vector);
}

TEST_CASE("Verify that the Graph BFS Algorithm - Large Sample") {
	GraphInitializer gc(data_vector, edgesVec);
	Graph outputGraph = gc.getGraph(); 

	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();
	vector<int> BFS_output = outputGraph.BFS(outputGraph.getVertices().at(0), feat_map);

	vector<int> correct_vector;
	correct_vector.push_back(523);
	correct_vector.push_back(1700);
	correct_vector.push_back(744);
	correct_vector.push_back(152);
	correct_vector.push_back(309);
	correct_vector.push_back(3428);
    REQUIRE(BFS_output == correct_vector);
}

TEST_CASE("Verify that Dijkstra Algorithm returns Correct Path - Small Sample") {
	GraphInitializer gc(data_vector_SMALL, edgesVec_SMALL);
	Graph outputGraph = gc.getGraph(); 
	GraphAlgo ga(outputGraph);
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();

	tuple<vector<Vertex>, int> djikstra_output = ga.DijkstraAlgo(outputGraph, outputGraph.getVertices().at(0), outputGraph.getVertices().at(4));
	reverse((get<0>(djikstra_output)).begin(), (get<0>(djikstra_output)).end());

	vector<std::string> correct_vector;
	correct_vector.push_back("1170");
	correct_vector.push_back("6194");
	correct_vector.push_back("255");
	correct_vector.push_back("220");
	correct_vector.push_back("380");
	correct_vector.push_back("60");

	REQUIRE(get<0>(djikstra_output).size() == correct_vector.size());

	for (int i = 0; i < (int)get<0>(djikstra_output).size(); i++) {
		REQUIRE(get<0>(djikstra_output).at(i) == correct_vector[i]);
	}
}

TEST_CASE("Verify that Dijkstra Algorithm returns Correct Distance -Small Sample") {
GraphInitializer gc(data_vector_SMALL, edgesVec_SMALL);
	Graph outputGraph = gc.getGraph(); 
	GraphAlgo ga(outputGraph);
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();

	tuple<vector<Vertex>, int> djikstra_output = ga.DijkstraAlgo(outputGraph, outputGraph.getVertices().at(0), outputGraph.getVertices().at(4));
	REQUIRE(get<1>(djikstra_output) == 71146);
}

TEST_CASE("Verify that A* Algorithm returns Correct Path - Small Sample") {
	GraphInitializer gc(data_vector_SMALL, edgesVec_SMALL);
	Graph outputGraph = gc.getGraph(); 
	GraphAlgo ga(outputGraph);
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();


	vector<Vertex> astar_output = ga.A_Star(outputGraph, outputGraph.getVertices().at(0), outputGraph.getVertices().at(4));
	reverse(((astar_output)).begin(), ((astar_output)).end());

	vector<std::string> correct_vector;
	correct_vector.push_back("1170");
	correct_vector.push_back("6194");
	correct_vector.push_back("255");
	correct_vector.push_back("220");
	correct_vector.push_back("380");
	correct_vector.push_back("60");

	REQUIRE(astar_output.size() == correct_vector.size());

	for (int i = 0; i < (int)(astar_output).size(); i++) {
		REQUIRE((astar_output).at(i) == correct_vector[i]);
	}
}


TEST_CASE("Verify that Dijkstra Algorithm returns Correct Path - Large Sample") {
	GraphInitializer gc(data_vector, edgesVec);
	Graph outputGraph = gc.getGraph(); 
	GraphAlgo ga(outputGraph);
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();

	tuple<vector<Vertex>, int> djikstra_output = ga.DijkstraAlgo(outputGraph, outputGraph.getVertices().at(218), outputGraph.getVertices().at(230));
	reverse((get<0>(djikstra_output)).begin(), (get<0>(djikstra_output)).end());

	vector<std::string> correct_vector;
	correct_vector.push_back("556");
	correct_vector.push_back("1809");
	correct_vector.push_back("2099");
	correct_vector.push_back("4341");

	REQUIRE(get<0>(djikstra_output).size() == correct_vector.size());

	for (int i = 0; i < (int)get<0>(djikstra_output).size(); i++) {
		REQUIRE(get<0>(djikstra_output).at(i) == correct_vector[i]);
	}
}

TEST_CASE("Verify that Dijkstra Algorithm returns Correct Distance - Large Sample") {
	GraphInitializer gc(data_vector, edgesVec);
	Graph outputGraph = gc.getGraph(); 
	GraphAlgo ga(outputGraph);
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();

	tuple<vector<Vertex>, int> djikstra_output = ga.DijkstraAlgo(outputGraph, outputGraph.getVertices().at(218), outputGraph.getVertices().at(230));

	REQUIRE(get<1>(djikstra_output) == 165839);
}

TEST_CASE("Verify that Dijkstra Algorithm returns Failed Destination - Large Sample") {
	GraphInitializer gc(data_vector, edgesVec);
	Graph outputGraph = gc.getGraph(); 
	GraphAlgo ga(outputGraph);
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();

	tuple<vector<Vertex>, int> djikstra_output = ga.DijkstraAlgo(outputGraph, outputGraph.getVertices().at(218), outputGraph.getVertices().at(40));

	REQUIRE(get<1>(djikstra_output) == -1);
}



TEST_CASE("Verify that A* Algorithm returns Correct Path - Large Sample") {
	GraphInitializer gc(data_vector, edgesVec);
	Graph outputGraph = gc.getGraph(); 
	GraphAlgo ga(outputGraph);
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();


	vector<Vertex> astar_output = ga.A_Star(outputGraph, outputGraph.getVertices().at(218), outputGraph.getVertices().at(230));
	reverse(((astar_output)).begin(), ((astar_output)).end());

	vector<std::string> correct_vector;
	correct_vector.push_back("556");
	correct_vector.push_back("1809");
	correct_vector.push_back("2099");
	correct_vector.push_back("4341");

	REQUIRE(astar_output.size() == correct_vector.size());

	for (int i = 0; i < (int)(astar_output).size(); i++) {
		REQUIRE((astar_output).at(i) == correct_vector[i]);
	}
}

TEST_CASE("Verify that A* Algorithm output contains Correct Edge Weight - Large Sample") {
	GraphInitializer gc(data_vector, edgesVec);
	Graph outputGraph = gc.getGraph(); 
	GraphAlgo ga(outputGraph);
	std::map<string, std::vector<string>> feat_map = gc.getFeaturesMap();

	vector<Vertex> astar_output = ga.A_Star(outputGraph, outputGraph.getVertices().at(218), outputGraph.getVertices().at(230));
	reverse(((astar_output)).begin(), ((astar_output)).end());

	vector<int> correct_vector;
	correct_vector.push_back(6549);
	correct_vector.push_back(13551);
	correct_vector.push_back(145739);
	correct_vector.push_back(4549864);

	for (int i = 0; i < (int)(astar_output).size() - 1; i++) {
		REQUIRE(outputGraph.getEdgeWeight((astar_output).at(i), (astar_output).at(i+1)) == correct_vector[i]);
	}
}

