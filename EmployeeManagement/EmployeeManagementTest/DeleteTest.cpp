#include "pch.h"
#include "../EmployeeManagement/MemoryDatabase.h"
#include "../EmployeeManagement/FileLogger.h"
#include "../EmployeeManagement/Parser.h"
#include "../EmployeeManagement/Del.h"

using namespace std;

class DeleteTest : public ::testing::Test {
protected:
	void SetUp() override {
		this->Database.push_back({ "20000001",
				Name("SAMSUNG", "KIM"),
				PhoneNum("1234", "5678"),
				BirthDay("2000", "01", "01"),
				"CL1",
				"ADV" });
		this->Database.push_back({ "20000002",
					Name("SAMSUNG", "KANG"),
					PhoneNum("2345", "6789"),
					BirthDay("2001", "02", "02"),
					"CL2",
					"PRO" });
		this->Database.push_back({ "20000003",
					Name("KAM", "KIM"),
					PhoneNum("3456", "5678"),
					BirthDay("2001", "02", "01"),
					"CL3",
					"EXP" });
		this->db.insert(Database[0]);
		this->db.insert(Database[1]);
		this->db.insert(Database[2]);
	}

public:
	MemoryDatabase db;
	vector<Employee> Database;
	Parser parser;
};

// name, phone, birth
TEST_F(DeleteTest, TestNoOption)
{
	vector<string> cmds;
	cmds.emplace_back("DEL, , , ,employeeNum,20000001");
	cmds.emplace_back("DEL, , , ,cl,CL3");
	cmds.emplace_back("DEL, , , ,certi,PRO");

	// DB[0] deleted
	Del delCommand0(parser.parseLine(cmds[0]));
	EXPECT_EQ(1, delCommand0.getDeleteResult(db));

	// DB[2] deleted
	Del delCommand1(parser.parseLine(cmds[1]));
	EXPECT_EQ(1, delCommand1.getDeleteResult(db));

	// DB[1] deleted
	Del delCommand2(parser.parseLine(cmds[2]));
	EXPECT_EQ(1, delCommand2.getDeleteResult(db));
}

// name, phone, birth
TEST_F(DeleteTest, TestName)
{
	vector<string> cmds;
	cmds.emplace_back("DEL, , , ,name,SAMSUNG KANG");
	cmds.emplace_back("DEL, ,-l, ,name,KIM");
	cmds.emplace_back("DEL, ,-f, ,name,SAMSUNG");

	// DB[1] deleted
	Del delCommand0(parser.parseLine(cmds[0]));
	EXPECT_EQ(1, delCommand0.getDeleteResult(db));

	// DB[0], DB[2] deleted
	Del delCommand1(parser.parseLine(cmds[1]));
	EXPECT_EQ(2, delCommand1.getDeleteResult(db));

	// Nothing
	Del delCommand2(parser.parseLine(cmds[2]));
	EXPECT_EQ(0, delCommand1.getDeleteResult(db));
}

TEST_F(DeleteTest, TestPhone)
{
	vector<string>cmds;
	cmds.emplace_back("DEL, ,-m, ,phoneNum,2345");
	cmds.emplace_back("DEL, ,-l, ,phoneNum,5678");
	cmds.emplace_back("DEL, , , ,phoneNum,010-1234-5678");

	// DB[1] deleted
	Del delCommand0(parser.parseLine(cmds[0]));
	EXPECT_EQ(1, delCommand0.getDeleteResult(db));

	// DB[0], DB[2] deleted
	Del delCommand1(parser.parseLine(cmds[1]));
	EXPECT_EQ(2, delCommand1.getDeleteResult(db));

	// DB[0] deleted
	db.insert(Database[0]);
	Del delCommand2(parser.parseLine(cmds[2]));
	EXPECT_EQ(1, delCommand1.getDeleteResult(db));
}

TEST_F(DeleteTest, TestBirth)
{
	vector<string>cmds;
	cmds.emplace_back("DEL,-p,-y, ,birthday,2001");
	cmds.emplace_back("DEL, , , ,birthday,20000101");
	cmds.emplace_back("DEL,-p,-d, ,birthday,01");
	cmds.emplace_back("DEL,-p,-m, ,birthday,02");

	// DB[1], DB[2] deleted
	Del delCommand0(parser.parseLine(cmds[0]));
	EXPECT_EQ(2, delCommand0.getDeleteResult(db));

	// DB[0] deleted
	Del delCommand1(parser.parseLine(cmds[1]));
	EXPECT_EQ(1, delCommand1.getDeleteResult(db));

	for (int i = 0; i < 3; i++)
		db.insert(Database[i]);
	// DB[0], DB[2] deleted
	Del delCommand2(parser.parseLine(cmds[2]));
	EXPECT_EQ(2, delCommand2.getDeleteResult(db));

	// DB[1] deleted
	Del delCommand3(parser.parseLine(cmds[3]));
	EXPECT_EQ(1, delCommand3.getDeleteResult(db));
}

