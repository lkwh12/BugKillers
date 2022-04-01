#pragma once

#include "IDatabase.h"

class MemoryDatabase : public IDatabase {
public:
	MemoryDatabase() : IDatabase() { }
	bool insert(const Employee& employee) override;
	std::vector<Employee> query(const Filter& filter) override;
	int remove(std::vector<std::string> employeeNumbers) override;
};
