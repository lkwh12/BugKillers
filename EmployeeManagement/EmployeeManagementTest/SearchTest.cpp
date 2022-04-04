#include "pch.h"
#include "../EmployeeManagement/Employee.h"
#include "../EmployeeManagement/Sch.h"
#include "../EmployeeManagement/Add.h"
#include "../EmployeeManagement/Parser.h"
#include "../EmployeeManagement/MemoryDatabase.h"
#include "../EmployeeManagement/FileLogger.h"

class SearchTest : public ::testing::Test {
protected:
	void SetUp() override {
		initCommands.push_back("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
		initCommands.push_back("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
		initCommands.push_back("ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");				
		initCommands.push_back("ADD, , , ,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO");				
		initCommands.push_back("ADD, , , ,19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO");							
		initCommands.push_back("ADD, , , ,17111236,VSID TVO,CL1,010-3669-1077,20120718,PRO");								
		initCommands.push_back("ADD, , , ,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO");									
		initCommands.push_back("ADD, , , ,08123556,WN XV,CL1,010-7986-5047,20100614,PRO");										
		initCommands.push_back("ADD, , , ,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV");											
		initCommands.push_back("ADD, , , ,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO");												
		initCommands.push_back("ADD, , , ,14130827,RPO JK,CL4,010-3231-1698,20090201,ADV");													
		initCommands.push_back("ADD, , , ,01122329,DN WD,CL4,010-7174-5680,20071117,PRO");														
		initCommands.push_back("ADD, , , ,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV");															
		initCommands.push_back("ADD, , , ,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV");																
		initCommands.push_back("ADD, , , ,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
		initCommands.push_back("ADD, , , ,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV");
		initCommands.push_back("ADD, , , ,12117017,LFIS JJIVL,CL1,010-7914-4067,20120812,PRO");
		initCommands.push_back("ADD, , , ,11125777,TKOQKIS HC,CL1,010-6734-2289,19991001,PRO");
		initCommands.push_back("ADD, , , ,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,19640130,PRO");
		initCommands.push_back("ADD, , , ,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO");
	}

	void TearDown() override {
		initCommands.clear();
	}

public:
	vector<string> initCommands;
};

TEST_F(SearchTest, BasicSearchTest) {

	FileIO outputfile("../EmployeeManagement/search_result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	for (const auto& cmd : initCommands) {
		Add addCommand(parser.parseLine(cmd));
		addCommand.execute(db, fileLogger);
	}
	Input input = parser.parseLine("SCH,-p, , ,certi,PRO");
	Sch schCommand1(input);
	fileLogger.setPrintDetail(input.getFirstOption() == "-p");
	EXPECT_EQ(schCommand1.execute(db, fileLogger), true);

	outputfile.close();
}

TEST_F(SearchTest, NoOptionSearchTest) {

	FileIO outputfile("../EmployeeManagement/search_result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	for (const auto& cmd : initCommands) {
		Add addCommand(parser.parseLine(cmd));
		addCommand.execute(db, fileLogger);
	}
	Input input = parser.parseLine("SCH, , , ,certi,ADV");
	Sch schCommand1(input);
	fileLogger.setPrintDetail(input.getFirstOption() == "-p");
	EXPECT_EQ(schCommand1.execute(db, fileLogger), true);

	outputfile.close();
}


TEST_F(SearchTest, SecondOptionSearchTest) {

	FileIO outputfile("../EmployeeManagement/search_result.txt", FileType::OUTPUT);
	MemoryDatabase db;
	FileLogger fileLogger(outputfile);
	Parser parser;

	outputfile.open();

	for (const auto& cmd : initCommands) {
		Add addCommand(parser.parseLine(cmd));
		addCommand.execute(db, fileLogger);
	}
	Input input = parser.parseLine("SCH, ,-m, ,birthday,09");
	Sch schCommand1(input);
	fileLogger.setPrintDetail(input.getFirstOption() == "-p");
	EXPECT_EQ(schCommand1.execute(db, fileLogger), true);

	outputfile.close();
}
