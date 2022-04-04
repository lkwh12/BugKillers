#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include "MemoryDatabase.h"

static std::function<bool(std::pair<std::string, std::shared_ptr<Employee>>)> getFilterFunction(const Filter& filter) {
	const auto& value = filter.getValue();
	const auto& column = filter.getColumn();
	switch (column) {
	case Filter::Column::NAME:
		return [value](const auto& kv) { return (kv.second->name_.name == value); };
	case Filter::Column::FIRST_NAME:
		return [value](const auto& kv) { return (kv.second->name_.firstName == value); };
	case Filter::Column::LAST_NAME:
		return [value](const auto& kv) { return (kv.second->name_.lastName == value); };
	case Filter::Column::TEL:
		return [value](const auto& kv) { return (kv.second->phoneNum_.phoneNum == value); };
	case Filter::Column::TEL_MIDDLE:
		return [value](const auto& kv) { return (kv.second->phoneNum_.middlePhoneNum == value); };
	case Filter::Column::TEL_LAST:
		return [value](const auto& kv) { return (kv.second->phoneNum_.lastPhoneNum == value); };
	case Filter::Column::BIRTH:
		return [value](const auto& kv) { return (kv.second->birthday_.birthDay == value); };
	case Filter::Column::BIRTH_YEAR:
		return [value](const auto& kv) { return (kv.second->birthday_.year == value); };
	case Filter::Column::BIRTH_MONTH:
		return [value](const auto& kv) { return (kv.second->birthday_.month == value); };
	case Filter::Column::BIRTH_DAY:
		return [value](const auto& kv) { return (kv.second->birthday_.day == value); };
	case Filter::Column::CL:
		return [value](const auto& kv) { return (kv.second->cl_ == value); };
	case Filter::Column::CERTI:
		return [value](const auto& kv) { return (kv.second->certi_ == value); };
	case Filter::Column::EMPLOYEE_NUM:
	default:
		return [value](const auto& kv) { return (kv.second->employeeNum_ == value); };
	}
}

static std::string adjustKey(const std::string key) {
	// if (key.length() != 8) return key;
	int yr = (key.at(0) - '0') * 10 + (key.at(1) - '0');
	if (69 <= yr) return "19" + key;
	return "20" + key;
}

bool MemoryDatabase::insert(const Employee& employee) {
	const std::string adjustedKey = adjustKey(employee.employeeNum_);
	if (map_.find(adjustedKey) != map_.end()) {
		return false;
	}

	map_[adjustedKey] = std::make_shared<Employee>(employee);

	return true;
}

std::vector<std::shared_ptr<Employee>> MemoryDatabase::query(const Filter& filter) {
	std::map<std::string, std::shared_ptr<Employee>> result;
	std::copy_if(map_.begin(), map_.end(), std::inserter(result, result.end()), getFilterFunction(filter));

	std::vector<shared_ptr<Employee>> list;
	list.reserve(result.size());
	for (auto& kv : result) list.push_back(kv.second);
	return list;
}

int MemoryDatabase::remove(std::vector<std::string> employeeNumbers) {
	int cnt = 0;
	for (auto& key : employeeNumbers) {
		auto adjustedKey = adjustKey(key);
		auto it = map_.find(adjustedKey);
		if (it != map_.end()) {
			map_.erase(it);
			cnt++;
		}
	}
	return cnt;
}
