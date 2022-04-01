#pragma once
#include <vector>
#include "Interface.h"
#include "Employee.h"
#include "Filter.h"

interface IDatabase {
	virtual bool insert(const Employee& employee) = 0;
	virtual std::vector<Employee> query(const Filter& filter) = 0;
	virtual int remove(std::vector<std::string> employeeNumbers) = 0;
};
