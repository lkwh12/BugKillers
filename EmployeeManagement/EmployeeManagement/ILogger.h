#pragma once
#include "Interface.h"
#include "FileIO.h"
#include "Employee.h"

const int MAX_PRINT_COUNT = 5;

interface ILogger {
	virtual void setPrintDetail(bool option) = 0;
	virtual int dump(const string& command, const vector<Employee>& outputList) = 0; // TODO: redefine
};
