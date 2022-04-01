#include "Parser.h"

vector<string> Parser::parse(const string& inputLine) {
	string token;
	vector<string> result;
	istringstream inputStream(inputLine);

	while (getline(inputStream, token, ',')) {
		result.emplace_back(token);
	}
	return result;
}