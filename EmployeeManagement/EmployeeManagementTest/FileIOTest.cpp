#include "pch.h"
#include "../EmployeeManagement/FileIO.cpp"

using namespace std;

TEST(TestCaseName, FileReadTest) {
	FileIO file("../EmployeeManagement/input_20_20.txt", FileType::INPUT);
	file.open();
	vector<string> lines = file.readLines();
	file.close();

	EXPECT_EQ(41, lines.size());
}

TEST(TestCaseName, FileWriteTest) {
	FileIO file("../EmployeeManagement/result.txt", FileType::OUTPUT);
	vector<string> samples = { "SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV",
							"DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV",
							"SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO",
							"MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO",
							"MOD,08123556,WN XV,CL1,010-7986-5047,20100614,PRO",
							"SCH,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV",
							"MOD,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV"
	};
	file.open();
	int ret = file.writeLines(samples);
	file.close();

	EXPECT_EQ(7, ret);
}

TEST(TestCaseName, FileSingleReadTest) {
	FileIO file("../EmployeeManagement/input_20_20.txt", FileType::INPUT);
	file.open();
	string line0 = file.readLine();
	string line1 = file.readLine();

	file.close();
	EXPECT_EQ(0, strcmp(line0.c_str(), "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV"));
	EXPECT_EQ(0, strcmp(line1.c_str(), "ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO"));
}

TEST(TestCaseName, FileSingleWriteTest) {
	FileIO file("../EmployeeManagement/result.txt", FileType::OUTPUT);
	string sample = "SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV";
	file.open();
	int ret = file.writeLine(sample);
	file.close();

	EXPECT_EQ(1, ret);
}
