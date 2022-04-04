#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"

using namespace std;

class Del : public ICommand {
public:
	Del(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) {
		return true;
	}

	bool doDelete(vector<Employee>& searchResult) {
		vector<string> payload = input.getPayload();
		string search_criteria = payload.at(0);
		string first_option = input.getFirstOption();
		string second_option = input.getSecondOption();

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
		return true;
	}

private:
	Input input;
	
	vector<shared_ptr<Employee>> deleteById(string first_option, string id);
	int deleteById(string id);

	vector<shared_ptr<Employee>> deleteByFullName(string first_option, string name);
	int deleteByFullName(string name);
	vector<shared_ptr<Employee>> deleteByFirstName(string first_option, string name);
	int deleteByFirstName(string name);
	vector<shared_ptr<Employee>> deleteByLastName(string first_option, string name);
	int deleteByLastName(string name);

	vector<shared_ptr<Employee>> deleteByFullPhone(string first_option, string phone);
	int deleteByFullPhone(string phone);
	vector<shared_ptr<Employee>> deleteByMiddlePhone(string first_option, string phone);
	int deleteByMiddlePhone(string phone);
	vector<shared_ptr<Employee>> deleteByLastPhone(string first_option, string phone);
	int deleteByLastPhone(string phone);

	vector<shared_ptr<Employee>> deleteByFullBirth(string first_option, string birth);
	int deleteByFullBirth(string birth);
	vector<shared_ptr<Employee>> deleteByYearBirth(string first_option, string birth);
	int deleteByYearBirth(string birth);
	vector<shared_ptr<Employee>> deleteByMonthBirth(string first_option, string birth);
	int deleteByMonthBirth(string birth);
	vector<shared_ptr<Employee>> deleteByDayBirth(string first_option, string birth);
	int deleteByDayBirth(string birth);

	vector<shared_ptr<Employee>> deleteByCl(string first_option, string cl);
	int deleteByCl(string cl);

	vector<shared_ptr<Employee>> deleteByCerti(string first_option, string certi);
	int deleteByCerti(string certi);
};
