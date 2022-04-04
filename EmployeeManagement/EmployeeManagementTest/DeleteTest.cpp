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
	FileIO outputfile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	FileLogger fileLogger(outputfile);

	vector<string> cmds;
	cmds.emplace_back("DEL, , , ,employeeNum, 20000001");
	cmds.emplace_back("DEL, , , ,name, SAMSUNG KIM");
	cmds.emplace_back("DEL, , , ,phone, 01012345678");
	cmds.emplace_back("DEL, , , ,birth, 20200101");
	cmds.emplace_back("DEL, , , ,cl, CL1");
	cmds.emplace_back("DEL, , , ,certi, PRO");

	// Return the number of deleted data
	Del delCommand1(parser.parseLine(cmds[0]));
	EXPECT_EQ(true, delCommand1.execute(db, fileLogger));
		

	//delCommand = new Del(parser.parseLine(cmds[0]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	//	EXPECT_EQ(1, deleteById(cmd_id));

	//delCommand = new Del(parser.parseLine(cmds[1]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	//	EXPECT_EQ(2, deleteByName(cmd_name));

	//delCommand = new Del(parser.parseLine(cmds[2]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
//	EXPECT_EQ(4, deleteByPhone(cmd_phone));

	//delCommand = new Del(parser.parseLine(cmds[3]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
//	EXPECT_EQ(8, deleteByBirth(cmd_birth));

	//delCommand = new Del(parser.parseLine(cmds[4]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
//	EXPECT_EQ(16, deleteByCl(cmd_cl));

	//delCommand = new Del(parser.parseLine(cmds[5]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
//	EXPECT_EQ(50, deleteByCerti(cmd_certi));
}

// name, phone, birth
TEST_F(DeleteTest, TestName)
{
	vector<string> cmds;
	cmds.emplace_back("DEL, , , ,name, SAMSUNG KANG");
	cmds.emplace_back("DEL,-p, , ,name, SAMSUNG KIM");
	cmds.emplace_back("DEL,-p,-f, ,name, SAMSUNG");
	cmds.emplace_back("DEL,-p,-l, ,name, KIM");


	// Return the number of deleted data
	//delCommand = new Del(parser.parseLine(cmds[0]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
//	EXPECT_EQ(NONE, deleteByName(cmd));

	//delCommand = new Del(parser.parseLine(cmds[1]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
//	EXPECT_EQ(1, deleteByName(cmd_n));


	// Return the set of delete data which has parameter's name
	//delCommand = new Del(parser.parseLine(cmds[2]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	vector<string>result_f;
	//	EXPECT_EQ(result_f, deleteByName(cmd_f));

	//delCommand = new Del(parser.parseLine(cmds[3]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	vector<string>result_l;
	//	EXPECT_EQ(result_l, deleteByName(cmd_l));

}

TEST_F(DeleteTest, TestPhone)
{
	vector<string>cmds;
	cmds.emplace_back("DEL, , , ,phone, 01098765432");
	cmds.emplace_back("DEL, , , ,phone, 01012345678");
	cmds.emplace_back("DEL,-p,-m, ,phone, 1234");
	cmds.emplace_back("DEL,-p,-l, ,phone, 5678");

	// Return the number of deleted data
	//delCommand = new Del(parser.parseLine(cmds[0]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	//	EXPECT_EQ(NONE, deleteByPhone(cmd));

	//delCommand = new Del(parser.parseLine(cmds[1]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	//	EXPECT_EQ(3, deleteByPhone(cmd_p));

	// Return the set of delete data which has parameter's name
	//delCommand = new Del(parser.parseLine(cmds[2]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	vector<string>result_m;
	//	EXPECT_EQ(result_m, deleteByPhone(cmd_m));

	//delCommand = new Del(parser.parseLine(cmds[3]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	vector<string>result_l;
	//	EXPECT_EQ(result_l, deleteByPhone(cmd_l));
}

TEST_F(DeleteTest, TestBirth)
{
	vector<string>cmds;
	cmds.emplace_back("DEL, , , ,birth, 20200131");
	cmds.emplace_back("DEL, , , ,birth, 20200101");
	cmds.emplace_back("DEL,-p,-y, ,birth, 2020");
	cmds.emplace_back("DEL,-p,-m, ,birth, 01");
	cmds.emplace_back("DEL,-p,-d, ,birth, 01");


	// Return the number of deleted data
	//delCommand = new Del(parser.parseLine(cmds[0]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	//	EXPECT_EQ(NONE, deleteByBirth(cmd));

	//delCommand = new Del(parser.parseLine(cmds[1]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	//	EXPECT_EQ(11, deleteByBirth(cmd_b));

	// Return the set of delete data which has parameter's name
	//delCommand = new Del(parser.parseLine(cmds[2]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	vector<string>result_y;
	//	EXPECT_EQ(result_y, deleteByBirth(cmd_y));

	//delCommand = new Del(parser.parseLine(cmds[3]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	vector<string>result_m;
	//	EXPECT_EQ(result_m, deleteByBirth(cmd_m));

	//delCommand = new Del(parser.parseLine(cmds[4]));
	//EXPECT_TRUE(delCommand->execute(database, logger), 1);
	vector<string>result_d;
	//	EXPECT_EQ(result_d, deleteByBirth(cmd_d));
}

