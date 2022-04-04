#pragma once
#include <map>
#include <string>
#include "IDatabase.h"

class MemoryDatabase : public IDatabase {
public:
	MemoryDatabase() : IDatabase() { }
	bool insert(const Employee& employee) override;
	std::vector<std::shared_ptr<Employee>> query(const Filter& filter) override;
	int remove(std::vector<std::string> employeeNumbers) override;
private:
	std::map<std::string, std::shared_ptr<Employee>> map_;
};
