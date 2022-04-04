#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"
#include <sstream>

class Add : public ICommand {
public:
	Add(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) {
		bool ret = true;

		ret = checkArgument(input.getPayload());
		if (ret == false) return false;

		Employee e = makeEmployeeData(input.getPayload());
		ret = db.insert(e);

		return ret;
	}

	vector<string> split(string str, char Delimiter) {
		istringstream iss(str);
		string buffer;
		vector<string> result;

		while (getline(iss, buffer, Delimiter)) {
			result.push_back(buffer);
		}

		return result;
	}

	bool checkArgument(const vector<string>& payloads) {
		if (payloads[0] == " " || payloads[0].length() != 8) {
			//throw invalid_argument("ERROR:: invalid Employee No format!");
			return false;
		}

		if (payloads[1] == " ") {
			//throw invalid_argument("ERROR:: invalid Name format!");
			return false;
		}

		if (payloads[3] == " " || payloads[3].length() != 13) {
			//throw invalid_argument("ERROR:: invalid Phone Number format!");
			return false;
		}

		if (payloads[4] == " " || payloads[4].length() != 8) {
			//throw invalid_argument("ERROR:: invalid birthday format!");
			return false;
		}

		if (payloads[2] == " " || payloads[5] == "") {
			//throw invalid_argument("ERROR:: invalid cl or certi format!");
			return false;
		}
		return true;
	}

	Employee makeEmployeeData(const vector<string>& payloads) {
		auto names = split(payloads[1], ' ');
		auto phoneNumbers = split(payloads[3], '-');

		return Employee(payloads[0],
			Name(names[0], names[1]),
			PhoneNum(phoneNumbers[1], phoneNumbers[2]),
			BirthDay(payloads[4].substr(0, 4), payloads[4].substr(4, 2), payloads[4].substr(6, 2)),
			payloads[2], payloads[5]);
	}

private:
	Input input;
};
