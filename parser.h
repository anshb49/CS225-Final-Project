#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>


std::string file_to_string(const std::string & filename);

std::vector<std::string> file_to_vector(const std::string & filename);


std::vector<std::vector<std::string>> file_to_data(const std::string & filename);
std::vector<std::vector<std::string>> file_to_edges(const std::string & filename);