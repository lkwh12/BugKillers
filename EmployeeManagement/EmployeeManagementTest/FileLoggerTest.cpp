#include "pch.h"
#include "../EmployeeManagement/FileLogger.cpp"

using namespace std;

TEST(TestCaseName, FileLoggerTest) {
	vector<shared_ptr<Employee>> outputList {
		make_shared<Employee>("08117441", Name("BMU", "MPOSXU"), PhoneNum("2703", "3153"),
		BirthDay("2001", "02", "15"), "CL3", "ADV" ),
		make_shared<Employee>( "88114052", Name("NQ", "LVARW"), PhoneNum("4528", "3059"),
		BirthDay("1991", "10", "21"), "CL4", "PRO" ),
		make_shared<Employee>( "17112609", Name("FB", "NTAWR"), PhoneNum("5645", "6122"),
		BirthDay("2005", "05", "20"), "CL4", "PRO" )
	};

	FileIO outputFile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	outputFile.open();

	FileLogger fileLogger(outputFile);
	ILogger& logger = fileLogger;
	logger.setPrintDetail(false);	
	int ret = logger.dump("SCH", outputList);
	outputFile.close();
	EXPECT_EQ(3, ret);
}

TEST(TestCaseName, FileLoggerDetailTest) {
	vector<shared_ptr<Employee>> outputList {
		make_shared<Employee>("08117441", Name("BMU", "MPOSXU"), PhoneNum("2703", "3153"),
		BirthDay("2001", "02", "15"), "CL3", "ADV" ),
		make_shared<Employee>("88114052", Name("NQ", "LVARW"), PhoneNum("4528", "3059"),
		BirthDay("1991", "10", "21"), "CL4", "PRO" ),
		make_shared<Employee>("17112609", Name("FB", "NTAWR"), PhoneNum("5645", "6122"),
		BirthDay("2005", "05", "20"), "CL4", "PRO" ),
		make_shared<Employee>("0211717", Name("SBILHUT", "LDEXRI"), PhoneNum("2814", "1699"),
		BirthDay("1995", "07", "04"), "CL4", "ADV" ),
		make_shared<Employee>("03113260", Name("HH", "LTUPF"), PhoneNum("5798", "5383"),
		BirthDay("1979", "10", "18"), "CL2", "PRO" ),
		make_shared<Employee>("08123556", Name("WN", "XV"), PhoneNum("7986", "5047"),
		BirthDay("2010", "06", "14"), "CL1", "PRO" )
	};

	FileIO outputFile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	outputFile.open();

	FileLogger fileLogger(outputFile);
	ILogger& logger = fileLogger;
	logger.setPrintDetail(true);
	int ret = logger.dump("SCH", outputList);
	outputFile.close();
	EXPECT_EQ(5, ret);
}

TEST(TestCaseName, FileLoggerNoneTest) {
	vector<shared_ptr<Employee>> outputList = {	};

	FileIO outputFile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	outputFile.open();

	FileLogger fileLogger(outputFile);
	ILogger& logger = fileLogger;
	logger.setPrintDetail(true);
	int ret = logger.dump("SCH", outputList);
	outputFile.close();
	EXPECT_EQ(0, ret);
}
