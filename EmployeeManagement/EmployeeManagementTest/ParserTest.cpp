#include "pch.h"
#include "../EmployeeManagement/Parser.cpp"

using namespace std;

class ParserTest : public ::testing::Test {
protected:
	void SetUp() override {
		pParser = new Parser();
	}

	void TearDown() override {
		delete pParser;
	}

public:
	Parser* pParser;
};

TEST_F(ParserTest, ParserTokenizeAddTest) {
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
}

TEST_F(ParserTest, ParserTokenizeModifyTest) {
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
}

TEST_F(ParserTest, ParserTokenizeSearchTest) {
	const string sample = "SCH,-p,-y, ,birthday,2003";
	vector<string> result = pParser->tokenize(sample);

	EXPECT_STREQ(result[0].c_str(), "SCH");
	EXPECT_STREQ(result[1].c_str(), "-p");
	EXPECT_STREQ(result[2].c_str(), "-y");
	EXPECT_STREQ(result[3].c_str(), " ");
	EXPECT_STREQ(result[4].c_str(), "birthday");
	EXPECT_STREQ(result[5].c_str(), "2003");
}

TEST_F(ParserTest, ParserTokenizeDeleteTest) {
	const string sample = "DEL,-p,-l, ,name,MPOSXU";
	vector<string> result = pParser->tokenize(sample);

	EXPECT_STREQ(result[0].c_str(), "DEL");
	EXPECT_STREQ(result[1].c_str(), "-p");
	EXPECT_STREQ(result[2].c_str(), "-l");
	EXPECT_STREQ(result[3].c_str(), " ");
	EXPECT_STREQ(result[4].c_str(), "name");
	EXPECT_STREQ(result[5].c_str(), "MPOSXU");
}

TEST_F(ParserTest, ParserAddTest) {
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
	EXPECT_EQ(result.getPayload().size(), 6);
}

TEST_F(ParserTest, ParserModifyTest) {
	const string sample = "MOD,-p, , ,name,FB NTAWR,birthday,20050520";
	Input result = pParser->parseLine(sample);

	EXPECT_STREQ(result.getCommand().c_str(), "MOD");
	EXPECT_STREQ(result.getFirstOption().c_str(), "-p");
	EXPECT_STREQ(result.getSecondOption().c_str(), " ");
	EXPECT_STREQ(result.getPayload()[0].c_str(), "name");
	EXPECT_STREQ(result.getPayload()[1].c_str(), "FB NTAWR");
	EXPECT_STREQ(result.getPayload()[2].c_str(), "birthday");
	EXPECT_STREQ(result.getPayload()[3].c_str(), "20050520");
	EXPECT_EQ(result.getPayload().size(), 4);
}

TEST_F(ParserTest, ParserSearchTest) {
	const string sample = "SCH,-p,-y, ,birthday,2003";
	Input result = pParser->parseLine(sample);

	EXPECT_STREQ(result.getCommand().c_str(), "SCH");
	EXPECT_STREQ(result.getFirstOption().c_str(), "-p");
	EXPECT_STREQ(result.getSecondOption().c_str(), "-y");
	EXPECT_STREQ(result.getPayload()[0].c_str(), "birthday");
	EXPECT_STREQ(result.getPayload()[1].c_str(), "2003");
	EXPECT_EQ(result.getPayload().size(), 2);
}

TEST_F(ParserTest, ParserDeleteTest) {
	const string sample = "DEL,-p,-l, ,name,MPOSXU";
	Input result = pParser->parseLine(sample);

	EXPECT_STREQ(result.getCommand().c_str(), "DEL");
	EXPECT_STREQ(result.getFirstOption().c_str(), "-p");
	EXPECT_STREQ(result.getSecondOption().c_str(), "-l");
	EXPECT_STREQ(result.getPayload()[0].c_str(), "name");
	EXPECT_STREQ(result.getPayload()[1].c_str(), "MPOSXU");
	EXPECT_EQ(result.getPayload().size(), 2);
}
