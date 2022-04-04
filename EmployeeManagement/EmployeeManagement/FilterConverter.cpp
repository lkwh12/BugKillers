#include "FilterConverter.h"

Filter FilterConverter::getFilter(Input& input) {
	string secondOption = input.getSecondOption();
	vector<string> payload = input.getPayload();

	if (payload.at(0) == "employeeNum") {
		if (secondOption == " ") {
			return Filter(Filter::Column::EMPLOYEE_NUM, payload.at(1));
		}
		else {
			throw invalid_argument("ERR: employeeNum Cannot have Second Option");
		}
	}
	else if (payload.at(0) == "name") {
		if (secondOption == " ") {
			return Filter(Filter::Column::NAME, payload.at(1));
		}
		else if (secondOption == "-f") {
			return Filter(Filter::Column::FIRST_NAME, payload.at(1));
		}
		else if (secondOption == "-l") {
			return Filter(Filter::Column::LAST_NAME, payload.at(1));
		}
		else {
			throw invalid_argument("ERR: Unknown Second Option in name");
		}
	}
	else if (payload.at(0) == "cl") {
		if (secondOption == " ") {
			return Filter(Filter::Column::CL, payload.at(1));
		}
		else {
			throw invalid_argument("ERR: cl Cannot have Second Option");
		}
	}
	else if (payload.at(0) == "phoneNum") {
		if (secondOption == " ") {
			return Filter(Filter::Column::TEL, payload.at(1));
		}
		else if (secondOption == "-m") {
			return Filter(Filter::Column::TEL_MIDDLE, payload.at(1));
		}
		else if (secondOption == "-l") {
			return Filter(Filter::Column::TEL_LAST, payload.at(1));
		}
		else {
			throw invalid_argument("ERR: Unknown Second Option in phoneNum");
		}
	}
	else if (payload.at(0) == "birthday") {
		if (secondOption == " ") {
			return Filter(Filter::Column::BIRTH, payload.at(1));
		}
		else if (secondOption == "-y") {
			return Filter(Filter::Column::BIRTH_YEAR, payload.at(1));
		}
		else if (secondOption == "-m") {
			return Filter(Filter::Column::BIRTH_MONTH, payload.at(1));
		}
		else if (secondOption == "-d") {
			return Filter(Filter::Column::BIRTH_DAY, payload.at(1));
		}
		else {
			throw invalid_argument("ERR: Unknown Second Option in birthday");
		}
	}
	else if (payload.at(0) == "certi") {
		if (secondOption == " ") {
			return Filter(Filter::Column::CERTI, payload.at(1));
		}
		else {
			throw invalid_argument("ERR: certi Cannot have Second Option");
		}
	}
	else
	{
		throw invalid_argument("ERR: Unknown Column");
	}
}
