#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"
#include "FilterConverter.h"

using namespace std;

#define QUEARY_RESULT vector<shared_ptr<Employee>>

constexpr auto SEARCH_COLUMN_INDEX    = (0);
constexpr auto SEARCH_CONTENTS_INDEX  = (1);
constexpr auto MODIFY_COLUMN_INDEX    = (2);
constexpr auto MODIFY_CONTENTS_INDEX  = (3);

constexpr auto FIRST_NAME_INDEX	      = (0);
constexpr auto LAST_NAME_INDEX        = (1);
constexpr auto NAME_DELIMITER         = (' ');

constexpr auto MIDDLE_PHONE_INDEX     = (1);
constexpr auto LAST_PHONE_INDEX       = (2);
constexpr auto PHONE_DELIMITER        = ('-');

constexpr auto BIRTHDAY_YEAR_START_INDEX    = (0);
constexpr auto BIRTHDAY_MONTH_START_INDEX   = (4);
constexpr auto BIRTHDAY_DAY_START_INDEX     = (6);
constexpr auto BIRTHDAY_YEAR_START_SIZE     = (4);
constexpr auto BIRTHDAY_MONTH_START_SIZE    = (2);
constexpr auto BIRTHDAY_DAY_START_SIZE      = (2);

constexpr auto EMPLOYEENUM_LENGTH           = (8);
constexpr auto NAME_CHUNK_SIZE              = (2);
constexpr auto NAME_LENGTH                  = (15);
constexpr auto PHONENUM_CHUNK_SIZE          = (3);
constexpr auto PHONENUM_LENGTH              = (13);
constexpr auto PHONENUM_MIDDLE_LENGTH       = (4);
constexpr auto PHONENUM_LAST_LENGTH         = (4);
constexpr auto BIRTHDAY_LENGTH              = (8);
constexpr auto BIRTHDAY_YEAR_LENGTH         = (4);
constexpr auto BIRTHDAY_MONTH_LENGTH        = (2);
constexpr auto BIRTHDAY_DAY_LENGTH          = (2);


#define GET_YEAR_FROM_BIRTH(birth)          (birth.substr(BIRTHDAY_YEAR_START_INDEX, BIRTHDAY_YEAR_START_SIZE))   
#define GET_MONTH_FROM_BIRTH(birth)         (birth.substr(BIRTHDAY_MONTH_START_INDEX, BIRTHDAY_MONTH_START_SIZE))
#define GET_DAY_FROM_BIRTH(birth)           (birth.substr(BIRTHDAY_DAY_START_INDEX, BIRTHDAY_DAY_START_SIZE))

#define GET_FUNCTION_INDEX(modifyColumn)    (find(ColumnForFunction.begin(), ColumnForFunction.end(), modifyColumn) - ColumnForFunction.begin())

#define VERIFY_COLUMN_EMPLOYEENUM(payloads, columnIndex, contentsIndex)     (payloads.at(columnIndex) == "employeeNum" && \
                                                                             payloads.at(contentsIndex).length() != EMPLOYEENUM_LENGTH)
#define VERIFY_COLUMN_NAME(payloads, columnIndex, contentsIndex)            (payloads.at(columnIndex) == "name" && \
	                                                                         payloads.at(contentsIndex).length() > NAME_LENGTH)
#define VERIFY_COLUMN_CL(payloads, columnIndex, contentsIndex)              (payloads.at(columnIndex) == "cl" && \
                                                                                (payloads.at(contentsIndex) != "CL1" && \
                                                                                 payloads.at(contentsIndex) != "CL2" && \
                                                                                 payloads.at(contentsIndex) != "CL3" && \
                                                                                 payloads.at(contentsIndex) != "CL4"))
#define VERIFY_COLUMN_PHONENUM(payloads, columnIndex, contentsIndex)        (payloads.at(columnIndex) == "phoneNum" && \
                                                                                 (payloads.at(contentsIndex).length() != PHONENUM_LENGTH && \
                                                                                  payloads.at(contentsIndex).length() != PHONENUM_MIDDLE_LENGTH && \
                                                                                  payloads.at(contentsIndex).length() != PHONENUM_LAST_LENGTH))
#define VERIFY_COLUMN_BIRTHDAY(payloads, columnIndex, contentsIndex)        (payloads.at(columnIndex) == "birthday" && \
                                                                                 (payloads.at(contentsIndex).length() != BIRTHDAY_LENGTH && \
                                                                                  payloads.at(contentsIndex).length() != BIRTHDAY_YEAR_LENGTH && \
                                                                                  payloads.at(contentsIndex).length() != BIRTHDAY_MONTH_LENGTH && \
                                                                                  payloads.at(contentsIndex).length() != BIRTHDAY_DAY_LENGTH))
#define VERIFY_COLUMN_CERTI(payloads, columnIndex, contentsIndex)           (payloads.at(columnIndex) == "certi" && \
                                                                                (payloads.at(contentsIndex) != "ADV" && \
                                                                                 payloads.at(contentsIndex) != "PRO" && \
                                                                                 payloads.at(contentsIndex) != "EX"))

#define VERIFY_SEARCH_COLUMN_EMPLOYEENUM(payloads)           VERIFY_COLUMN_EMPLOYEENUM(payloads, SEARCH_COLUMN_INDEX, SEARCH_CONTENTS_INDEX)
#define VERIFY_SEARCH_COLUMN_NAME(payloads)                  VERIFY_COLUMN_NAME(payloads, SEARCH_COLUMN_INDEX, SEARCH_CONTENTS_INDEX)
#define VERIFY_SEARCH_COLUMN_CL(payloads)                    VERIFY_COLUMN_CL(payloads, SEARCH_COLUMN_INDEX, SEARCH_CONTENTS_INDEX)
#define VERIFY_SEARCH_COLUMN_PHONENUM(payloads)              VERIFY_COLUMN_PHONENUM(payloads, SEARCH_COLUMN_INDEX, SEARCH_CONTENTS_INDEX)
#define VERIFY_SEARCH_COLUMN_BIRTHDAY(payloads)              VERIFY_COLUMN_BIRTHDAY(payloads, SEARCH_COLUMN_INDEX, SEARCH_CONTENTS_INDEX)
#define VERIFY_SEARCH_COLUMN_CERTI(payloads)                 VERIFY_COLUMN_CERTI(payloads, SEARCH_COLUMN_INDEX, SEARCH_CONTENTS_INDEX)

#define VERIFY_MODIFY_COLUMN_EMPLOYEENUM(payloads)           VERIFY_COLUMN_EMPLOYEENUM(payloads, MODIFY_COLUMN_INDEX, MODIFY_CONTENTS_INDEX)
#define VERIFY_MODIFY_COLUMN_NAME(payloads)                  VERIFY_COLUMN_NAME(payloads, MODIFY_COLUMN_INDEX, MODIFY_CONTENTS_INDEX)
#define VERIFY_MODIFY_COLUMN_CL(payloads)                    VERIFY_COLUMN_CL(payloads, MODIFY_COLUMN_INDEX, MODIFY_CONTENTS_INDEX)
#define VERIFY_MODIFY_COLUMN_PHONENUM(payloads)              VERIFY_COLUMN_PHONENUM(payloads, MODIFY_COLUMN_INDEX, MODIFY_CONTENTS_INDEX)
#define VERIFY_MODIFY_COLUMN_BIRTHDAY(payloads)              VERIFY_COLUMN_BIRTHDAY(payloads, MODIFY_COLUMN_INDEX, MODIFY_CONTENTS_INDEX)
#define VERIFY_MODIFY_COLUMN_CERTI(payloads)                 VERIFY_COLUMN_CERTI(payloads, MODIFY_COLUMN_INDEX, MODIFY_CONTENTS_INDEX)

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

	virtual bool execute(IDatabase& db, ILogger& logger) override {

		Filter filter = filterConverter_.getFilter(input_);

		if (!checkSearchExcetion()) {
	        return false;
		}

		QUEARY_RESULT queryResult = db.query(filter);

		logger.dump(input_.getCommand(), queryResult);

		if (doModify(queryResult)) {
			return true;
		}

		return false;
	}

	bool doModify(QUEARY_RESULT& searchResult) {
		vector<string> payload = input_.getPayload();
		
		if (!checkModifyExcetion()) {
			return false;
		}

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

	bool checkSearchExcetion() {
		const vector<string>& payloads = input_.getPayload();

		if (VERIFY_SEARCH_COLUMN_EMPLOYEENUM(payloads)) {
			return false;
		}
		else if (VERIFY_SEARCH_COLUMN_NAME(payloads)) {
			return false;
		}
		else if (VERIFY_SEARCH_COLUMN_CL(payloads)) {
			return false;
		}
		else if (VERIFY_SEARCH_COLUMN_PHONENUM(payloads)) {
			return false;
		}
		else if (VERIFY_SEARCH_COLUMN_BIRTHDAY(payloads)) {
			return false;
		}
		else if (VERIFY_SEARCH_COLUMN_CERTI(payloads)) {
			return false;
		}
		return true;
	}

	bool checkModifyExcetion() {
		const vector<string>& payloads = input_.getPayload();

		if (VERIFY_MODIFY_COLUMN_EMPLOYEENUM(payloads)) {
			return false;
		}
		else if (VERIFY_MODIFY_COLUMN_NAME(payloads)) {
			return false;
		}
		else if (VERIFY_MODIFY_COLUMN_CL(payloads)) {
			return false;
		}
		else if (VERIFY_MODIFY_COLUMN_PHONENUM(payloads)) {
			return false;
		}
		else if (VERIFY_MODIFY_COLUMN_BIRTHDAY(payloads)) {
			return false;
		}
		else if (VERIFY_MODIFY_COLUMN_CERTI(payloads)) {
			return false;
		}
		return true;
	}

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
