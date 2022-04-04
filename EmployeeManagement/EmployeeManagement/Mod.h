#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"
#include "FilterConverter.h"

using namespace std;

class Mod : public ICommand {
public:
	Mod(const Input& input) : input_(input) {

	}

	virtual bool execute(IDatabase& db, ILogger& logger) {

		Filter filter = filterConverter_.getFilter(input_);

		makeFilter(filter);

		vector<shared_ptr<Employee>> queryResult = db.query(filter);

		logger.dump("MOD", queryResult);

		doModify(queryResult);

		return true;
	}

	void makeFilter(Filter& filter) {
		filter = filterConverter_.getFilter(input_);
	}

	bool doModify(vector<shared_ptr<Employee>>& searchResult) {
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

private:
	Input input_;
	FilterConverter filterConverter_;

	void modifyEmployeeNum(vector<shared_ptr<Employee>>& searchResult, const string& modifyContents) {
		for (auto& Employee : searchResult) {
			Employee->employeeNum_ = modifyContents;
		}
	}

	void modifyName(vector<shared_ptr<Employee>>& searchResult, const string& modifyContents) {
		vector<string> ModifyName = splitByDelimiter(modifyContents, ' ');

		for (auto& Employee : searchResult) {
			Employee->name_ = Name(ModifyName[0], ModifyName[1]);
		}
	}

	void modifyPhoneNum(vector<shared_ptr<Employee>>& searchResult, const string& modifyContents) {
		vector<string> modifyPhoneNumber = splitByDelimiter(modifyContents, '-');

		for (auto& Employee : searchResult) {
			Employee->phoneNum_ = PhoneNum(modifyPhoneNumber[1], modifyPhoneNumber[2]);
		}
	}

	void modifyBirthDay(vector<shared_ptr<Employee>>& searchResult, const string& modifyContents) {

		for (auto& Employee : searchResult) {
			Employee->birthday_ = BirthDay(modifyContents.substr(0, 2), modifyContents.substr(2, 2), modifyContents.substr(4, 2));
		}
	}

	void modifyCl(vector<shared_ptr<Employee>>& searchResult, const string& modifyContents) {
		for (auto& Employee : searchResult) {
			Employee->cl_ = modifyContents;
		}
	}

	void modifyCerti(vector<shared_ptr<Employee>>& searchResult, const string& modifyContents) {
		for (auto& Employee : searchResult) {
			Employee->certi_ = modifyContents;
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
