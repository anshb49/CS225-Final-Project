#include "parser.h"
#include <string>

std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

std::vector<std::string> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::string> out;

	if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			out.push_back(*iter);
			++iter;
		}
	}

	return out;
} 


std::vector<std::vector<std::string>>file_to_data(const std::string & filename) {
	std::vector<std::string> vectorRepr = file_to_vector(filename);
	std::vector<std::vector<std::string>> data_vector;//convert file into vector

	//go through each word in the vector
	for (auto word : vectorRepr) {
		int rowCount = 0;
		int stringCount = 0;
		std::stringstream s_stream(word);


		std::vector<std::string> row;
		while (s_stream.good()) {//make sure current string is not NULL
			std::string temp;
			getline(s_stream, temp, ',');
			row.push_back(temp);//push back into row vector
			stringCount++;
		}
		data_vector.push_back(row);//push back created set of vector strings
	}

	return data_vector;
} 

std::vector<std::vector<std::string>>file_to_edges(const std::string & filename) {
	std::vector<std::vector<std::string>> edges_vector;
	std::vector<std::string> edgesRepr = file_to_vector(filename); //convert file into vector
	
	//go through each word in the vector
	for (auto e : edgesRepr) {
		int rowCount = 0;
		int stringCount = 0;
		std::stringstream s_stream(e);

		std::vector<std::string> row;
		while (s_stream.good()) { //make sure current string is not NULL
			std::string temp;
			getline(s_stream, temp, ',');
			row.push_back(temp); //push back into row vector
			stringCount++;
		}
		edges_vector.push_back(row); //push back created set of vector strings
	}

	return edges_vector;
} 

std::string printBFSOutput(std::vector<int> inputBins) {
	std::cout << "" <<std::endl;
	std::string output_string = ""; //empty string

	//Loop through inputBins and add to output string for correct format
	for (int i = 0; i < (int)inputBins.size() - 1; i++) {
        if (i < 1) {
			output_string = output_string + "0 - 1000 Views: " + std::to_string(inputBins[i]) + " || ";

        } else if (i < 2) {
			output_string = output_string + " 1000 - 10000 Views: " + std::to_string(inputBins[i]) + " || ";

        } else if (i < 3) {
			output_string = output_string + " 10001 - 50000 Views: " + std::to_string(inputBins[i]) + " || ";

        } else if (i < 4) {
			output_string = output_string + " 50001 - 100000 Views: " + std::to_string(inputBins[i]) + " || ";

        } else {
			output_string = output_string + " Over 100000 Views: " + std::to_string(inputBins[i]) + " || ";

        }
	}

	output_string = output_string + " Total Vertices: " + std::to_string(inputBins[(int)inputBins.size() - 1]) + " || ";
	return output_string;

}



