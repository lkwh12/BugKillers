#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"

using namespace std;

class Mod : public ICommand {
public:
	Mod(const Input& input) : input_(input) {

	}

	virtual bool execute(IDatabase& db, ILogger& logger) {
		return true;
	}

	bool doModify(vector<Employee>& searchResult) {
		vector<string> payload = input_.getPayload();
		string modifyColumn = payload.at(2);

		if (modifyColumn == "employeeNum") {
			modifyEmployeeNum(searchResult, payload.at(3));
		}
		else if (modifyColumn == "name") {
			modifyName(searchResult, payload.at(3));
		}
		else if (modifyColumn == "phoneNum") {
			modifyPhoneNum(searchResult, payload.at(3));
		}
		else if (modifyColumn == "birthday") {
			modifyBirthDay(searchResult, payload.at(3));
		}
		else if (modifyColumn == "cl") {
			modifyCl(searchResult, payload.at(3));
		}
		else if (modifyColumn == "certi") {
			modifyCerti(searchResult, payload.at(3));
		}
		else {
			// throw invalid_argument("ERR: Invalid Option0 Type");
			return false;
		}

		return true;
	}

	bool makeFilter(Filter& filter) {
		string SecondOption = input_.getSecondOption();
		vector<string> payload = input_.getPayload();

		if (payload.at(0) == "employeeNum") {
			if (SecondOption == " ") {
				filter = Filter(Filter::Column::EMPLOYEE_NUM, payload.at(1));
			}
			else {
				// throw invalid_argument("ERR: employeeNum Can Not Have Option2");
				return false;
			}
		}
		else if (payload.at(0) == "name") {
			if (SecondOption == " ") {
				filter = Filter(Filter::Column::NAME, payload.at(1));
			}
			else if (SecondOption == "-f") {
				filter = Filter(Filter::Column::FIRST_NAME, payload.at(1));
			}
			else if (SecondOption == "-l") {
				filter = Filter(Filter::Column::LAST_NAME, payload.at(1));
			}
			else {
				// throw invalid_argument("ERR: Invalid Option2 At name");
				return false;
			}

		}
		else if (payload.at(0) == "cl") {
			if (SecondOption == " ") {
				filter = Filter(Filter::Column::CL, payload.at(1));
			}
			else {
				// throw invalid_argument("ERR: cl Can Not Have Option2");
				return false;
			}
		}
		else if (payload.at(0) == "phoneNum") {
			if (SecondOption == " ") {
				filter = Filter(Filter::Column::TEL, payload.at(1));
			}
			else if (SecondOption == "-m") {
				filter = Filter(Filter::Column::TEL_MIDDLE, payload.at(1));
			}
			else if (SecondOption == "-l") {
				filter = Filter(Filter::Column::TEL_LAST, payload.at(1));
			}
			else {
				// throw invalid_argument("ERR: Invalid Option2 At phoneNum");
				return false;
			}
		}
		else if (payload.at(0) == "birthday") {
			if (SecondOption == " ") {
				filter = Filter(Filter::Column::BIRTH, payload.at(1));
			}
			else if (SecondOption == "-y") {
				filter = Filter(Filter::Column::BIRTH_YEAR, payload.at(1));
			}
			else if (SecondOption == "-m") {
				filter = Filter(Filter::Column::BIRTH_MONTH, payload.at(1));
			}
			else if (SecondOption == "-d") {
				filter = Filter(Filter::Column::BIRTH_DAY, payload.at(1));
			}
			else {
				// throw invalid_argument("ERR: Invalid Option2 At birthday");
				return false;
			}
		}
		else if (payload.at(0) == "certi") {
			if (SecondOption == " ") {
				filter = Filter(Filter::Column::CERTI, payload.at(1));
			}
			else {
				// throw invalid_argument("ERR: cl Can Not Have Option2");
				return false;
			}
		}
		else
		{
			// throw invalid_argument("ERR: Invalid Condition Column Type");
			return false;
		}

		return true;
	}
private:
	Input input_;

	void modifyEmployeeNum(vector<Employee>& searchResult, const string& modifyContents) {
		for (auto& Employee : searchResult) {
			Employee.employeeNum_ = modifyContents;
		}
	}

	void modifyName(vector<Employee>& searchResult, const string& modifyContents) {
		vector<string> ModifyName = splitByDelimiter(modifyContents, ' ');

		for (auto& Employee : searchResult) {
			Employee.name_ = Name(ModifyName[0], ModifyName[1]);
		}
	}

	void modifyPhoneNum(vector<Employee>& searchResult, const string& modifyContents) {
		vector<string> modifyPhoneNumber = splitByDelimiter(modifyContents, '-');

		for (auto& Employee : searchResult) {
			Employee.phoneNum_ = PhoneNum(modifyPhoneNumber[1], modifyPhoneNumber[2]);
		}
	}

	void modifyBirthDay(vector<Employee>& searchResult, const string& modifyContents) {

		for (auto& Employee : searchResult) {
			Employee.birthday_ = BirthDay(modifyContents.substr(0, 2), modifyContents.substr(2, 2), modifyContents.substr(4, 2));
		}
	}

	void modifyCl(vector<Employee>& searchResult, const string& modifyContents) {
		for (auto& Employee : searchResult) {
			Employee.cl_ = modifyContents;
		}
	}

	void modifyCerti(vector<Employee>& searchResult, const string& modifyContents) {
		for (auto& Employee : searchResult) {
			Employee.certi_ = modifyContents;
		}
	}

	vector<string> splitByDelimiter(string str, char Delimiter) {
		istringstream iss(str);
		string buffer;

		vector<string> result;

		while (getline(iss, buffer, Delimiter)) {
			result.push_back(buffer);
		}

		return result;
	}
};
