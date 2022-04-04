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
	EXPECT_EQ(addCommand1.execute(db, fileLogger), true);

	Add addCommand2(parser.parseLine("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO"));
	EXPECT_EQ(addCommand2.execute(db, fileLogger), true);

	Add addCommand3(parser.parseLine("ADD, , , ,18115050,TTETHU HBO,CL3,010-4581-2050,20080718,ADV"));
	EXPECT_EQ(addCommand3.execute(db, fileLogger), true);

	outputfile.close();
}

TEST(AddTest, SameEmpNoAddCase) {

	FileIO outputfile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	Add addCommand1(parser.parseLine("ADD, , , ,19120999,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV"));
	EXPECT_EQ(addCommand1.execute(db, fileLogger), true);

	Add addCommand2(parser.parseLine("ADD, , , ,19120999,FB NTAWR,CL4,010-5645-6122,19861203,PRO"));
	EXPECT_EQ(addCommand2.execute(db, fileLogger), false);

	Add addCommand3(parser.parseLine("ADD, , , ,19120999,TTETHU HBO,CL3,010-4581-2050,20080718,ADV"));
	EXPECT_EQ(addCommand3.execute(db, fileLogger), false);

	outputfile.close();
}

TEST(AddTest, WrongValueAddCase) {
	FileIO outputfile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	Add addCommand1(parser.parseLine("ADD, , , ,15120999,VXIHXOTH JHOP,CL3,010-32112-2609,197471211,ADV"));
	EXPECT_EQ(addCommand1.execute(db, fileLogger), false);

	Add addCommand2(parser.parseLine("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,198631203,PRO"));
	EXPECT_EQ(addCommand2.execute(db, fileLogger), false);

	Add addCommand3(parser.parseLine("ADD, , , ,18115023232350,TTETHU HBO,CL3,010-2050,20080718,ADV"));
	EXPECT_EQ(addCommand3.execute(db, fileLogger), false);

	outputfile.close();
}

TEST(AddTest, NullValueAddCase) {
	FileIO outputfile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	Add addCommand1(parser.parseLine("ADD, , , ,15120999, ,CL3,010-3112-2609,19771211,ADV"));
	EXPECT_EQ(addCommand1.execute(db, fileLogger), false);

	Add addCommand2(parser.parseLine("ADD, , , ,17112609,FB NTAWR,CL4, ,19861203,PRO"));
	EXPECT_EQ(addCommand2.execute(db, fileLogger), false);

	Add addCommand3(parser.parseLine("ADD, , , ,18115050,TTETHU HBO, ,010-4581-2050,20080718,ADV"));
	EXPECT_EQ(addCommand3.execute(db, fileLogger), false);

	outputfile.close();
}
