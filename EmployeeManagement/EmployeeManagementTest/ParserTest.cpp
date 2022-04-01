#include "pch.h"
#include "../EmployeeManagement/Parser.cpp"

using namespace std;

TEST(TestCaseName, ParserTokenizeAddTest) {
	Parser* pParser = new Parser();
	const string sample = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";
	vector<string> result = pParser->tokenize(sample);

	EXPECT_STREQ(result[0].c_str(), "ADD");
	EXPECT_STREQ(result[1].c_str(), " ");
	EXPECT_STREQ(result[2].c_str(), " ");
	EXPECT_STREQ(result[3].c_str(), " ");
	EXPECT_STREQ(result[4].c_str(), "15123099");
	EXPECT_STREQ(result[5].c_str(), "VXIHXOTH JHOP");
	EXPECT_STREQ(result[6].c_str(), "CL3");
	EXPECT_STREQ(result[7].c_str(), "010-3112-2609");
	EXPECT_STREQ(result[8].c_str(), "19771211");
	EXPECT_STREQ(result[9].c_str(), "ADV");
	delete pParser;
}

TEST(TestCaseName, ParserTokenizeModifyTest) {
	Parser* pParser = new Parser();
	const string sample = "MOD,-p, , ,name,FB NTAWR,birthday,20050520";
	vector<string> result = pParser->tokenize(sample);

	EXPECT_STREQ(result[0].c_str(), "MOD");
	EXPECT_STREQ(result[1].c_str(), "-p");
	EXPECT_STREQ(result[2].c_str(), " ");
	EXPECT_STREQ(result[3].c_str(), " ");
	EXPECT_STREQ(result[4].c_str(), "name");
	EXPECT_STREQ(result[5].c_str(), "FB NTAWR");
	EXPECT_STREQ(result[6].c_str(), "birthday");
	EXPECT_STREQ(result[7].c_str(), "20050520");
	delete pParser;
}

TEST(TestCaseName, ParserTokenizeSearchTest) {
	Parser* pParser = new Parser();
	const string sample = "SCH,-p,-y, ,birthday,2003";
	vector<string> result = pParser->tokenize(sample);

	EXPECT_STREQ(result[0].c_str(), "SCH");
	EXPECT_STREQ(result[1].c_str(), "-p");
	EXPECT_STREQ(result[2].c_str(), "-y");
	EXPECT_STREQ(result[3].c_str(), " ");
	EXPECT_STREQ(result[4].c_str(), "birthday");
	EXPECT_STREQ(result[5].c_str(), "2003");
	delete pParser;
}

TEST(TestCaseName, ParserTokenizeDeleteTest) {
	Parser* pParser = new Parser();
	const string sample = "DEL,-p,-l, ,name,MPOSXU";
	vector<string> result = pParser->tokenize(sample);

	EXPECT_STREQ(result[0].c_str(), "DEL");
	EXPECT_STREQ(result[1].c_str(), "-p");
	EXPECT_STREQ(result[2].c_str(), "-l");
	EXPECT_STREQ(result[3].c_str(), " ");
	EXPECT_STREQ(result[4].c_str(), "name");
	EXPECT_STREQ(result[5].c_str(), "MPOSXU");
	delete pParser;
}

TEST(TestCaseName, ParserAddTest) {
	Parser* pParser = new Parser();
	const string sample = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";
	Input result = pParser->parseLine(sample);

	EXPECT_STREQ(result.getCommand().c_str(), "ADD");
	EXPECT_STREQ(result.getFirstOption().c_str(), " ");
	EXPECT_STREQ(result.getSecondOption().c_str(), " ");
	EXPECT_STREQ(result.getPayload()[0].c_str(), "15123099");
	EXPECT_STREQ(result.getPayload()[1].c_str(), "VXIHXOTH JHOP");
	EXPECT_STREQ(result.getPayload()[2].c_str(), "CL3");
	EXPECT_STREQ(result.getPayload()[3].c_str(), "010-3112-2609");
	EXPECT_STREQ(result.getPayload()[4].c_str(), "19771211");
	EXPECT_STREQ(result.getPayload()[5].c_str(), "ADV");

	delete pParser;
}

TEST(TestCaseName, ParserModifyTest) {
	Parser* pParser = new Parser();
	const string sample = "MOD,-p, , ,name,FB NTAWR,birthday,20050520";
	Input result = pParser->parseLine(sample);

	EXPECT_STREQ(result.getCommand().c_str(), "MOD");
	EXPECT_STREQ(result.getFirstOption().c_str(), "-p");
	EXPECT_STREQ(result.getSecondOption().c_str(), " ");
	EXPECT_STREQ(result.getPayload()[0].c_str(), "name");
	EXPECT_STREQ(result.getPayload()[1].c_str(), "FB NTAWR");
	EXPECT_STREQ(result.getPayload()[2].c_str(), "birthday");
	EXPECT_STREQ(result.getPayload()[3].c_str(), "20050520");

	delete pParser;
}

TEST(TestCaseName, ParserSearchTest) {
	Parser* pParser = new Parser();
	const string sample = "SCH,-p,-y, ,birthday,2003";
	Input result = pParser->parseLine(sample);

	EXPECT_STREQ(result.getCommand().c_str(), "SCH");
	EXPECT_STREQ(result.getFirstOption().c_str(), "-p");
	EXPECT_STREQ(result.getSecondOption().c_str(), "-y");
	EXPECT_STREQ(result.getPayload()[0].c_str(), "birthday");
	EXPECT_STREQ(result.getPayload()[1].c_str(), "2003");

	delete pParser;
}

TEST(TestCaseName, ParserDeleteTest) {
	Parser* pParser = new Parser();
	const string sample = "DEL,-p,-l, ,name,MPOSXU";
	Input result = pParser->parseLine(sample);

	EXPECT_STREQ(result.getCommand().c_str(), "DEL");
	EXPECT_STREQ(result.getFirstOption().c_str(), "-p");
	EXPECT_STREQ(result.getSecondOption().c_str(), "-l");
	EXPECT_STREQ(result.getPayload()[0].c_str(), "name");
	EXPECT_STREQ(result.getPayload()[1].c_str(), "MPOSXU");

	delete pParser;
}
