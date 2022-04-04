#pragma once
#include "Filter.h"
#include "Input.h"
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class FilterConverter {
public:
	Filter getFilter(Input& input);
};
