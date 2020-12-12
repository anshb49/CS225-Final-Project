#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

/**
 * Converts passed in filename into a string
 * @param - filename is the input file to be converted
 * @return - inputted filename into a string
*/
std::string file_to_string(const std::string & filename);

/**
 * Converts passed in filename into a vector
 * @param - filename is the input file to be converted
 * @return - inputted filename into a vector
*/
std::vector<std::string> file_to_vector(const std::string & filename);

/**
 * Converts passed in filename into a vector of vector of strings to be used in graphinitializer
 * @param - filename is the input file to be converted
 * @return - vector of vector of string containing correct features information
*/
std::vector<std::vector<std::string>> file_to_data(const std::string & filename);

/**
 * Converts passed in filename into a vector of vector of strings to be used in graphinitializer
 * @param - filename is the input file to be converted
 * @return - vector of vector of string containing correct edges information
*/
std::vector<std::vector<std::string>> file_to_edges(const std::string & filename);

/**
 * Prints out category values for views that are calculated in BFS
 * @param - inputBins is the output of BFS method to be converted into string
 * @return - string of information of views that are calculated successfully
*/
std::string printBFSOutput(std::vector<int> inputBins);