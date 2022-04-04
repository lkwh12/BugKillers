#pragma once

#include "ICommand.h"
#include "FilterConverter.h"
#include "Filter.h"
#include "Input.h"

using namespace std;

class Del : public ICommand {
public:
	Del(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) {
		// check Argument

		filter = filterConverter.getFilter(input);
		if (doDelete(db, filter))
			return true;
		return false;
	}

	bool doDelete(IDatabase& db, Filter& filter) {
		vector<string> payload = input.getPayload();
		string first_option = input.getFirstOption();

		if (filter.getColumn() == Filter::Column::EMPLOYEE_NUM) {
			int res = deleteById(db, filter);
		}
		/*
		if (search_criteria == "employeeNum") {
			if (first_option == " ") {
				deleteById(payload.at(1));
			}
			else if (first_option == "-p") {
				deleteById(first_option, payload.at(1));
			}
			else {
				throw invalid_argument("Error : Invalid first option");
				return false;
			}
		}
		else if (search_criteria == "name") {
			if (second_option == " ") {
				if (first_option == " ") {
					deleteByFullName(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByFullName(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else if (second_option == "-f") {
				if (first_option == " ") {
					deleteByFirstName(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByFirstName(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else if (second_option == "-l") {
				if (first_option == " ") {
					deleteByLastName(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByLastName(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else {
				throw invalid_argument("Error : Invalid second option");
				return false;
			}
		}
		else if (search_criteria == "phoneNum") {
			if (second_option == " ") {
				if (first_option == " ") {
					deleteByFullPhone(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByFullPhone(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else if (second_option == "-m") {
				if (first_option == " ") {
					deleteByMiddlePhone(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByMiddlePhone(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else if (second_option == "-l") {
				if (first_option == " ") {
					deleteByLastPhone(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByLastPhone(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else {
				throw invalid_argument("Error : Invalid second option");
				return false;
			}
		}
		else if (search_criteria == "birthday") {
			if (second_option == " ") {
				if (first_option == " ") {
					deleteByFullBirth(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByFullBirth(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else if (second_option == "-y") {
				if (first_option == " ") {
					deleteByYearBirth(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByYearBirth(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else if (second_option == "-m") {
				if (first_option == " ") {
					deleteByMonthBirth(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByMonthBirth(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else if (second_option == "-d") {
				if (first_option == " ") {
					deleteByDayBirth(payload.at(1));
				}
				else if (first_option == "-p") {
					deleteByDayBirth(first_option, payload.at(1));
				}
				else {
					throw invalid_argument("Error : Invalid first option");
					return false;
				}
			}
			else {
				throw invalid_argument("Error : Invalid second option");
				return false;
			}
		}
		else if (search_criteria == "cl") {
			if (first_option == " ") {
				deleteByCl(payload.at(1));
			}
			else if (first_option == "-p") {
				deleteByCl(first_option, payload.at(1));
			}
			else {
				throw invalid_argument("Error : Invalid first option");
				return false;
			}
		}
		else if (search_criteria == "certi") {
			if (first_option == " ") {
				deleteByCerti(payload.at(1));
			}
			else if (first_option == "-p") {
				deleteByCerti(first_option, payload.at(1));
			}
			else {
				throw invalid_argument("Error : Invalid first option");
				return false;
			}
		}
		else {
			throw invalid_argument("Error : Invalid search option");
			return false;
		}
		*/
		return true;
	}

private:
	Input input;
	FilterConverter filterConverter;
	Filter filter;

	int deleteById(IDatabase& db, Filter& filter)
	{
		
		auto result = db.query(Filter(Filter::Column::EMPLOYEE_NUM, filter.getValue()));
	//	auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return result.size();
	}

};
