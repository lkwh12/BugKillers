#include "pch.h"
#include "../EmployeeManagement/Employee.h"
#include "../EmployeeManagement/Add.h"
#include "../EmployeeManagement/Parser.h"
#include "../EmployeeManagement/MemoryDatabase.h"
#include "../EmployeeManagement/FileLogger.h"

TEST(AddTest, BasicAddTest) {

	FileIO outputfile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	Add addCommand1(parser.parseLine("ADD, , , ,15120999,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV"));
	shared_ptr<Employee> e1 = addCommand1.execute(db, fileLogger).back();
	EXPECT_EQ(e1->employeeNum_, "15120999");
	EXPECT_EQ(e1->name_.name, "VXIHXOTH JHOP");
	EXPECT_EQ(e1->cl_, "CL3");
	EXPECT_EQ(e1->phoneNum_.phoneNum, "010-3112-2609");
	EXPECT_EQ(e1->birthday_.birthDay, "19771211");
	EXPECT_EQ(e1->certi_, "ADV");

	Add addCommand2(parser.parseLine("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO"));
	shared_ptr<Employee> e2 = addCommand2.execute(db, fileLogger).back();
	EXPECT_EQ(e2->employeeNum_, "17112609");
	EXPECT_EQ(e2->name_.name, "FB NTAWR");
	EXPECT_EQ(e2->cl_, "CL4");
	EXPECT_EQ(e2->phoneNum_.phoneNum, "010-5645-6122");
	EXPECT_EQ(e2->birthday_.birthDay, "19861203");
	EXPECT_EQ(e2->certi_, "PRO");

	Add addCommand3(parser.parseLine("ADD, , , ,18115050,TTETHU HBO,CL3,010-4581-2050,20080718,ADV"));
	shared_ptr<Employee> e3 = addCommand3.execute(db, fileLogger).back();
	EXPECT_EQ(e3->employeeNum_, "18115050");
	EXPECT_EQ(e3->name_.name, "TTETHU HBO");
	EXPECT_EQ(e3->cl_, "CL3");
	EXPECT_EQ(e3->phoneNum_.phoneNum, "010-4581-2050");
	EXPECT_EQ(e3->birthday_.birthDay, "20080718");
	EXPECT_EQ(e3->certi_, "ADV");

	outputfile.close();
}

TEST(AddTest, SameEmpNoAddCase) {

	FileIO outputfile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	Add addCommand1(parser.parseLine("ADD, , , ,19120999,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV"));
	shared_ptr<Employee> e1 = addCommand1.execute(db, fileLogger).back();
	EXPECT_EQ(e1->employeeNum_, "19120999");
	EXPECT_EQ(e1->name_.name, "VXIHXOTH JHOP");
	EXPECT_EQ(e1->cl_, "CL3");
	EXPECT_EQ(e1->phoneNum_.phoneNum, "010-3112-2609");
	EXPECT_EQ(e1->birthday_.birthDay, "19771211");
	EXPECT_EQ(e1->certi_, "ADV");

	Add addCommand2(parser.parseLine("ADD, , , ,19120999,FB NTAWR,CL4,010-5645-6122,19861203,PRO"));
	EXPECT_EQ((int)addCommand2.execute(db, fileLogger).size(), 0);

	Add addCommand3(parser.parseLine("ADD, , , ,19120999,TTETHU HBO,CL3,010-4581-2050,20080718,ADV"));
	EXPECT_EQ((int)addCommand3.execute(db, fileLogger).size(), 0);

	outputfile.close();
}

TEST(AddTest, WrongValueAddCase) {
	FileIO outputfile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	Add addCommand1(parser.parseLine("ADD, , , ,15120999,VXIHXOTH JHOP,CL3,010-32112-2609,197471211,ADV"));
	EXPECT_EQ((int)addCommand1.execute(db, fileLogger).size(), 0);

	Add addCommand2(parser.parseLine("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,198631203,PRO"));
	EXPECT_EQ((int)addCommand2.execute(db, fileLogger).size(), 0);

	Add addCommand3(parser.parseLine("ADD, , , ,18115023232350,TTETHU HBO,CL3,010-2050,20080718,ADV"));
	EXPECT_EQ((int)addCommand3.execute(db, fileLogger).size(), 0);

	outputfile.close();
}

TEST(AddTest, NullValueAddCase) {
	FileIO outputfile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	Add addCommand1(parser.parseLine("ADD, , , ,15120999, ,CL3,010-3112-2609,19771211,ADV"));
	EXPECT_EQ((int)addCommand1.execute(db, fileLogger).size(), 0);

	Add addCommand2(parser.parseLine("ADD, , , ,17112609,FB NTAWR,CL4, ,19861203,PRO"));
	EXPECT_EQ((int)addCommand2.execute(db, fileLogger).size(), 0);

	Add addCommand3(parser.parseLine("ADD, , , ,18115050,TTETHU HBO, ,010-4581-2050,20080718,ADV"));
	EXPECT_EQ((int)addCommand3.execute(db, fileLogger).size(), 0);

	outputfile.close();
}
