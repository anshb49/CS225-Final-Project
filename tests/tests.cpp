#include <string>
#include <vector>

#include "../cs225/catch/catch.hpp"
#include "../parser.h"


TEST_CASE("Verify parsing data vector values are accurate") {
    std::vector<std::vector<std::string>> data_vector = file_to_data("musae_ENGB_target.csv");
	//std::string res = file_to_data("tests/smallSample.txt");
	// always check "expected" == "actual" --> be consistent
	REQUIRE(data_vector[14].at(5) == "639");
    REQUIRE(data_vector[33].at(5) == "634");
    REQUIRE(data_vector[88].at(5) == "5956");
}

TEST_CASE("Verify parsing edges vector values are accurate") {
	std::vector<std::vector<std::string>> edgesVec = file_to_edges("musae_ENGB_edges.csv"); //MAYBE USE PARSER::?;	//std::string res = file_to_data("tests/smallSample.txt");
	// always check "expected" == "actual" --> be consistent
    REQUIRE(edgesVec[0].at(1) == "255");
	REQUIRE(edgesVec[23].at(0) == "3");
    REQUIRE(edgesVec[617].at(1) == "3017");
}

/*
TEST_CASE("Verify that file_to_vector works on a small example") {
	std::vector<std::string> res = file_to_vector("tests/smallSample.txt");
	std::string expected[] = {"hello", "students", "of", "cs", "225", "!!!"};
	
	REQUIRE(6 == res.size());

	for (int i = 0; i < res.size(); i++) {
		REQUIRE(expected[i] == res[i]);
	}
}
*/