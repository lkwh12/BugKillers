#include "FileLogger.h"

int FileLogger::dump(const string& command, const vector<Employee>& outputList) {
	string result;
	if (outputList.size() == 0) {
		result = command + ",NONE";
		file_.writeLine(result);
		return 0;
	}
	if (bPrintDetail == false) {
		result = command + "," + to_string(outputList.size());
		file_.writeLine(result);
		return (int)outputList.size();
	}
	int cnt = 0;
	for (auto item : outputList) {
		if (cnt >= MAX_PRINT_COUNT) break;
		result = command + "," + item.employeeNum_ + "," + item.name_.name + "," +
				item.cl_ + "," + item.phoneNum_.phoneNum + "," +
				item.birthday_.birthDay + "," + item.certi_;
		file_.writeLine(result);
		cnt++;
	}
	return cnt;
}
