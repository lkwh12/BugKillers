#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"
#include "FilterConverter.h"

using namespace std;

#define QUEARY_RESULT vector<shared_ptr<Employee>>

constexpr auto MODIFY_COLUMN_INDEX    = (2);
constexpr auto MODIFY_CONTENTS_INDEX  = (3);

constexpr auto FIRST_NAME_INDEX	      = (0);
constexpr auto LAST_NAME_INDEX        = (1);
constexpr auto NAME_DELIMITER         = (' ');

constexpr auto MIDDLE_PHONE_INDEX     = (1);
constexpr auto LAST_PHONE_INDEX       = (2);
constexpr auto PHONE_DELIMITER        = ('-');

constexpr auto BIRTHDAT_YEAR_START_INDEX    = (0);
constexpr auto BIRTHDAT_MONTH_START_INDEX   = (4);
constexpr auto BIRTHDAT_DAY_START_INDEX     = (6);
constexpr auto BIRTHDAT_YEAR_START_SIZE     = (4);
constexpr auto BIRTHDAT_MONTH_START_SIZE    = (2);
constexpr auto BIRTHDAT_DAY_START_SIZE      = (2);

#define GET_YEAR_FROM_BIRTH(birth)          (birth.substr(BIRTHDAT_YEAR_START_INDEX, BIRTHDAT_YEAR_START_SIZE))   
#define GET_MONTH_FROM_BIRTH(birth)         (birth.substr(BIRTHDAT_MONTH_START_INDEX, BIRTHDAT_MONTH_START_SIZE))
#define GET_DAY_FROM_BIRTH(birth)           (birth.substr(BIRTHDAT_DAY_START_INDEX, BIRTHDAT_DAY_START_SIZE))

#define GET_FUNCTION_INDEX(modifyColumn)    (find(ColumnForFunction.begin(), ColumnForFunction.end(), modifyColumn) - ColumnForFunction.begin())

typedef void MODIFY(QUEARY_RESULT &, const string &);

class Mod : public ICommand {
public:
	Mod(const Input& input) : input_(input) {
		pModify[(int)Mod::FunctionIndex::E_EMPLOYNUM]   = &Mod::modifyEmployeeNum;
		pModify[(int)Mod::FunctionIndex::E_NAME]        = &Mod::modifyName;
		pModify[(int)Mod::FunctionIndex::E_PHONENUM]    = &Mod::modifyPhoneNum;
		pModify[(int)Mod::FunctionIndex::E_BIRTHDAY]    = &Mod::modifyBirthDay;
		pModify[(int)Mod::FunctionIndex::E_CL]          = &Mod::modifyCl;
		pModify[(int)Mod::FunctionIndex::E_CERTI]       = &Mod::modifyCerti;
	}

	virtual bool execute(IDatabase& db, ILogger& logger) {

		Filter filter = filterConverter_.getFilter(input_);

		QUEARY_RESULT queryResult = db.query(filter);

		logger.dump("MOD", queryResult);

		if (doModify(queryResult)) {
			return true;
		}

		return false;
	}

	bool doModify(QUEARY_RESULT& searchResult) {
		vector<string> payload = input_.getPayload();
		string modifyColumn = payload.at(MODIFY_COLUMN_INDEX);

		(this->*pModify[GET_FUNCTION_INDEX(modifyColumn)])(searchResult, payload.at(MODIFY_CONTENTS_INDEX));

		return true;
	}

private:
	Input input_;
	FilterConverter filterConverter_;
	vector<string> ColumnForFunction = {
		"employeeNum",
		"name",
		"phoneNum",
		"birthday",
		"cl",
		"certi" 
	};
	
	enum class FunctionIndex {
		E_EMPLOYNUM,
		E_NAME,
		E_PHONENUM,
		E_BIRTHDAY,
		E_CL,
		E_CERTI,
		E_COLUMN_MAX_COUNT
	};

	void (Mod::*pModify[(int)Mod::FunctionIndex::E_COLUMN_MAX_COUNT])(QUEARY_RESULT&, const string&);

	void modifyEmployeeNum(QUEARY_RESULT& searchResult, const string& modifyContents) {
		for (auto& Employee : searchResult) {
			Employee->employeeNum_ = modifyContents;
		}
	}

	void modifyName(QUEARY_RESULT& searchResult, const string& modifyContents) {
		vector<string> ModifyName = splitByDelimiter(modifyContents, ' ');

		for (auto& Employee : searchResult) {
			Employee->name_ = Name(ModifyName[0], ModifyName[1]);
		}
	}

	void modifyPhoneNum(QUEARY_RESULT& searchResult, const string& modifyContents) {
	vector<string> modifyPhoneNumber = splitByDelimiter(modifyContents, PHONE_DELIMITER);

		for (auto& Employee : searchResult) {
			Employee->phoneNum_ = PhoneNum(modifyPhoneNumber.at(MIDDLE_PHONE_INDEX), modifyPhoneNumber.at(LAST_PHONE_INDEX));
		}
	}

	void modifyBirthDay(QUEARY_RESULT& searchResult, const string& modifyContents) {

		for (auto& Employee : searchResult) {
			Employee->birthday_ = BirthDay(GET_YEAR_FROM_BIRTH(modifyContents), GET_MONTH_FROM_BIRTH(modifyContents), GET_DAY_FROM_BIRTH(modifyContents));
		}
	}

	void modifyCl(QUEARY_RESULT& searchResult, const string& modifyContents) {
		for (auto& Employee : searchResult) {
			Employee->cl_ = modifyContents;
		}
	}

	void modifyCerti(QUEARY_RESULT& searchResult, const string& modifyContents) {
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
