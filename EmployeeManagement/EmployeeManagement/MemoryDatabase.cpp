#include "MemoryDatabase.h"

bool MemoryDatabase::insert(const Employee& employee) {
	return false;
}

std::vector<Employee> MemoryDatabase::query(const Filter& filter) {
	static std::vector<Employee> emtpyList;
	return emtpyList;
}

int MemoryDatabase::remove(std::vector<std::string> employeeNumbers) {
	return 0;
}
