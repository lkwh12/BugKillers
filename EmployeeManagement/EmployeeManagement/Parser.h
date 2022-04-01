#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Input.h"

using namespace std;

class Parser {
public:
	vector<string> tokenize(const string& inputLine);
	Input parseLine(const string& inputLine);
};
