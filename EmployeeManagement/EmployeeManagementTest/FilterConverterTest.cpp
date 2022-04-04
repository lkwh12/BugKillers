#include "pch.h"
#include "../EmployeeManagement/FilterConverter.cpp"
#include "../EmployeeManagement/Parser.h"

using namespace std;

TEST(TestCaseName, FilterConverterTest) {
	string sample = "MOD,-p,-m, ,phoneNum,3112,certi,EX";
	FilterConverter filterConverter;
	Parser parser;
	Filter res = filterConverter.getFilter(parser.parseLine(sample));
	EXPECT_EQ(Filter::Column::TEL_MIDDLE, res.getColumn());
	EXPECT_EQ("3112", res.getValue());
}
