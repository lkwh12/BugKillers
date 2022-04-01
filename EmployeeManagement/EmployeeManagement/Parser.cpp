#include "Parser.h"

Input Parser::parseLine(const string& inputLine) {	
	vector<string> tokens = tokenize(inputLine);
	vector<string> payload;
	for (int i = 4; i < tokens.size(); i++) {
		payload.emplace_back(tokens[i]);
	}
	Input result(tokens[0], tokens[1], tokens[2], payload);

	return result;
}

vector<string> Parser::tokenize(const string& inputLine) {
	string token;
	vector<string> result;
	istringstream inputStream(inputLine);

	while (getline(inputStream, token, ',')) {
		result.emplace_back(token);
	}
	return result;
}
