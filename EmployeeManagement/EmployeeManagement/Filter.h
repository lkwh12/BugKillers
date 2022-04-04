#pragma once
#include <string>

class Filter {
public:
	enum class Column {
		EMPLOYEE_NUM,
		NAME,
		FIRST_NAME,
		LAST_NAME,
		TEL,
		TEL_MIDDLE,
		TEL_LAST,
		BIRTH,
		BIRTH_YEAR,
		BIRTH_MONTH,
		BIRTH_DAY,
		CL,
		CERTI
	};

	Filter() : column(Column::EMPLOYEE_NUM) { };
	Filter(Column column, const std::string& value) : column(column), value(value) { };

	void setColumn(Column column) { this->column = column;  }
	const Column getColumn() const { return this->column; }

	void setValue(const std::string& value) { this->value = value; }
	const std::string& getValue() const { return this->value; }

private:
	Column column;
	std::string value;
};
