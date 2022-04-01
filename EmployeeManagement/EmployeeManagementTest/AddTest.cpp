#include "pch.h"
#include "../EmployeeManagement/Employee.h"
#include "../EmployeeManagement/Add.h"
#include "../EmployeeManagement/Parser.h"

class AddTest : public ::testing::Test {
protected:
	void SetUp() override {
		commands.emplace_back("ADD, , , ,15120999,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
		commands.emplace_back("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
		commands.emplace_back("ADD, , , ,18115050,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");
	}

	void TearDown() override {
		commands.clear();
	}

public:
	Parser parser;
	vector<string> commands;
	Add* addCommand;
};

TEST_F(AddTest, BasicAddTest) {
	
	addCommand = new Add(parser.parseLine(commands[0]));
	//EXPECT_EQ(addCommand->execute(database, logger), 0);

	addCommand = new Add(parser.parseLine(commands[1]));
	//EXPECT_EQ(addCommand->execute(database, logger), 0);

	addCommand = new Add(parser.parseLine(commands[2]));
	//EXPECT_EQ(addCommand->execute(database, logger), 0);
}

TEST_F(AddTest, SameEmpNoAddCase) {

	addCommand = new Add(parser.parseLine("ADD, , , ,19120999,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV"));
	//EXPECT_EQ(addCommand->execute(database, logger), 0);
	
	addCommand = new Add(parser.parseLine("ADD, , , ,19120999,FB NTAWR,CL4,010-5645-6122,19861203,PRO"));
	//EXPECT_EQ(addCommand->execute(database, logger), -1);
	
	addCommand = new Add(parser.parseLine("ADD, , , ,19120999,TTETHU HBO,CL3,010-4581-2050,20080718,ADV"));
	//EXPECT_EQ(addCommand->execute(database, logger), -1);

	
}

TEST_F(AddTest, WrongValueAddCase) {

	addCommand = new Add(parser.parseLine("ADD, , , ,15120999,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV"));
	//EXPECT_EQ(addCommand->execute(database, logger), -1);

	addCommand = new Add(parser.parseLine("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO"));
	//EXPECT_EQ(addCommand->execute(database, logger), -1);

	addCommand = new Add(parser.parseLine("ADD, , , ,18115023232350,TTETHU HBO,CL3,010-2050,20080718,ADV"));
	//EXPECT_EQ(addCommand->execute(database, logger), -1);
}


TEST_F(AddTest, NullValueAddCase) {

	addCommand = new Add(parser.parseLine("ADD, , , ,15120999, ,CL3,010-3112-2609,19771211,ADV"));
	//EXPECT_EQ(addCommand->execute(database, logger), -1);

	addCommand = new Add(parser.parseLine("ADD, , , ,17112609,FB NTAWR,CL4, ,19861203,PRO"));
	//EXPECT_EQ(addCommand->execute(database, logger), -1);

	addCommand = new Add(parser.parseLine("ADD, , , ,18115050,TTETHU HBO, ,010-4581-2050,20080718,ADV"));
	//EXPECT_EQ(addCommand->execute(database, logger), -1);
}
