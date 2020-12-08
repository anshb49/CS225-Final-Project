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
	std::vector<std::vector<std::string>> data_vector;

	for (auto word : vectorRepr) {
		int rowCount = 0;
		int stringCount = 0;
		std::stringstream s_stream(word);

		std::vector<std::string> row;
		while (s_stream.good()) {
			std::string temp;
			getline(s_stream, temp, ',');
			row.push_back(temp);
			stringCount++;
		}
		data_vector.push_back(row);
	}

	return data_vector;
} 

std::vector<std::vector<std::string>>file_to_edges(const std::string & filename) {
	std::vector<std::vector<std::string>> edges_vector;
	std::vector<std::string> edgesRepr = file_to_vector(filename);
	
	for (auto word : edgesRepr) {
		int rowCount = 0;
		int stringCount = 0;
		std::stringstream s_stream(word);

		std::vector<std::string> row;
		while (s_stream.good()) {
			std::string temp;
			getline(s_stream, temp, ',');
			row.push_back(temp);
			stringCount++;
		}
		edges_vector.push_back(row);
	}

	return edges_vector;
} 



