#include <iostream>
#include <vector>
#include "parser.h"


int main(int argc, const char * argv[]) {
	std::cout << "Filename: " << argv[1] << std::endl;
	
	// convert file to string representation
	std::cout << "String Representation:" << std::endl;
	//std::cout << file_to_string(argv[1]) << std::endl;
	
	// convert file to vector representation

	std::vector<std::vector<std::string>> data_vector;

	std::cout << "Vector Representation:" << std::endl;
	std::string fileTarget = argv[1];

	std::vector<std::string> vectorRepr = file_to_vector("musae_"+fileTarget+"_target.csv");
	
	for (auto word : vectorRepr) {
		int rowCount = 0;
		int stringCount = 0;
		std::stringstream s_stream(word);

		std::vector<std::string> row;
		while (s_stream.good()) {
			/* code */
			std::string temp;
			getline(s_stream, temp, ',');
			row.push_back(temp);
			stringCount++;
		}
		data_vector.push_back(row);
	}

	//std::cout<<data_vector[15].at(5) << std::endl; // testcase
	//std::cout<<data_vector[34].at(5)<< std::endl;// testcase
	//std::cout<<data_vector[89].at(5)<< std::endl;// testcase


	std::vector<std::vector<std::string>> edgesVec;
	std::vector<std::string> edgesRepr = file_to_vector("musae_"+fileTarget+"_edges.csv");

	for (auto word : edgesRepr) {
		int rowCount = 0;
		int stringCount = 0;
		std::stringstream s_stream(word);

		std::vector<std::string> row;
		while (s_stream.good()) {
			/* code */
			std::string temp;
			getline(s_stream, temp, ',');
			row.push_back(temp);
			stringCount++;
		}
		edgesVec.push_back(row);
	}	

	std::cout<<edgesVec[1].at(0)<< std::endl;// testcase
	std::cout<<edgesVec[1].at(1)<< std::endl;// testcase

	//Psuedocode for Graph
	//Parse through edges file to create 2d matrix using similar code from above
	//parse all these column values as ints and use sorting algorithm 
		//possibly use binary serach or another search algorithm to improve efficiency
	//Create new vertex based on "from" value using all its information
	//create second vertex based on "to" value using its info
	//Use graph class to create edges between first column to second column from edges matrix

}