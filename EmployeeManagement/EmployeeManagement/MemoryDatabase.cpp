#include <exception>
#include "MemoryDatabase.h"

bool MemoryDatabase::insert(const Employee& employee) {
	const std::string key = employee.employeeNum_;
	if (map_.find(key) != map_.end()) {
		//throw std::invalid_argument("key exists: " + key);
		return false;
	}

	map_[key] = std::make_shared<Employee>(employee);

	return true;
}

std::vector<std::shared_ptr<Employee>> MemoryDatabase::query(const Filter& filter) {
	std::vector<shared_ptr<Employee>> emtpyList;
	return emtpyList;
}

int MemoryDatabase::remove(std::vector<std::string> employeeNumbers) {
	return 0;
}
