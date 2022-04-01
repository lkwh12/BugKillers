#pragma once
#include <string>

class Filter {
public:
	enum Column {
		FIRST_NAME,
		LAST_NAME,
		TEL_MIDDLE,
		TEL_LAST,
		BIRTH_YEAR,
		BIRTH_MONTH,
		BIRTH_DAY
	};

	Filter() : column(FIRST_NAME) { };

	void setColumn(Column column) { this->column = column;  }
	Column getColumn() { return this->column; }

	void setName(const std::string& value) { this->value = value; }
	const std::string& getValue() const { return this->value; }

private:
	Column column;
	std::string value;
};
