#include <iostream>
#include <vector>
#include "parser.h"


int main(int argc, const char * argv[]) {
	std::cout << "Filename: " << argv[1] << std::endl;
	
	// convert file to string representation
	std::cout << "String Representation:" << std::endl;
	//std::cout << file_to_string(argv[1]) << std::endl;
	
	// convert file to vector representation
    //std::vector<string> id_vector;
	std::vector<std::string> ID_vector;
	std::vector<std::string> days_vector;
	std::vector<std::string> mature_vector;
	std::vector<std::string> views_vector;
	std::vector<std::string> partner_vector;
	std::vector<std::string> newID_vector;

	std::vector<std::vector<std::string>> data_vector;

	std::cout << "Vector Representation:" << std::endl;
	std::vector<std::string> vectorRepr = file_to_vector(argv[1]);
	
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

	std::cout<<data_vector[15].at(5) << std::endl;
	std::cout<<data_vector[34].at(5)<< std::endl;
	std::cout<<data_vector[89].at(5)<< std::endl;


}