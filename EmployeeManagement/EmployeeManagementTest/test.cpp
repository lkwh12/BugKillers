#include "pch.h"
#include "../EmployeeManagement/FileIO.h"
#include "../EmployeeManagement/Parser.h"
#include "../EmployeeManagement/CommandFactory.cpp"
#include "../EmployeeManagement/MemoryDatabase.h"
#include "../EmployeeManagement/FileLogger.h"

static bool checkFileEQ(FileIO& fileDb, FileIO& fileQuery) {
	vector<string> stringDb = fileDb.readLines();
	vector<string> stringQuery = fileQuery.readLines();
	if (stringDb.size() != stringQuery.size()) return false;
	for (int i = 0; i < stringDb.size(); i++) {
		if (strcmp(stringDb[i].c_str(), stringQuery[i].c_str()) != 0) {
			return false;
		}
	}
	return true;
}

TEST(FullScenarioTest, TC1) {
	FileIO inputFile("../EmployeeManagement/input_20_20.txt", FileType::INPUT);
	FileIO outputFile("../EmployeeManagement/result.txt", FileType::OUTPUT);
	inputFile.open();
	outputFile.open();

	Parser parser;
	MemoryDatabase memDB;
	IDatabase& DB = memDB;
	FileLogger fileLogger(outputFile);
	ILogger& logger = fileLogger;

	CommandFactory commandFactory;

	while (1) {
		string inputLine = inputFile.readLine();
		if (inputLine == "") break;
		Input input = parser.parseLine(inputLine);
		logger.setPrintDetail(input.getFirstOption() == "-p");
		shared_ptr<ICommand> cmd = commandFactory.createCommand(input);
		cmd->execute(DB, logger);
	}

	inputFile.close();
	outputFile.close();

	FileIO dbFile("../EmployeeManagement/output_20_20.txt", FileType::INPUT);
	FileIO queryFile("../EmployeeManagement/result.txt", FileType::INPUT);
	dbFile.open();
	queryFile.open();
	bool ret = checkFileEQ(dbFile, queryFile);
	dbFile.close();
	queryFile.close();

	EXPECT_EQ(true, ret);
}

TEST(FullScenarioTest, 100KTC) {
	FileIO outputFile("../EmployeeManagement/result100K.txt", FileType::OUTPUT);
	outputFile.open();

	Parser parser;
	MemoryDatabase memDB;
	IDatabase& DB = memDB;
	FileLogger fileLogger(outputFile);
	ILogger& logger = fileLogger;

	CommandFactory commandFactory;
	vector<string> inputString;

	for (int i = 100000; i > 0; i--) {
		string str = "ADD, , , ," + to_string(10000000 + i) + ",SAMSUNG KIM,CL4,010-1234-5678,20000101,PRO";
		inputString.emplace_back(str);
	}
	inputString.emplace_back("DEL, , , ,employeeNum,18115040");
	inputString.emplace_back("SCH, , , ,certi,PRO");
	inputString.emplace_back("SCH,-p, , ,cl,CL4");
	inputString.emplace_back("DEL, ,-l, ,name,KIM");
	for (int i = 0; i < (100000 + 4); i++) {
		string inputLine = inputString[i];
		Input input = parser.parseLine(inputLine);
		logger.setPrintDetail(input.getFirstOption() == "-p");
		shared_ptr<ICommand> cmd = commandFactory.createCommand(input);
		cmd->execute(DB, logger);
	}

	outputFile.close();

	FileIO dbFile("../EmployeeManagement/output100K.txt", FileType::INPUT);
	FileIO queryFile("../EmployeeManagement/result100K.txt", FileType::INPUT);
	dbFile.open();
	queryFile.open();
	bool ret = checkFileEQ(dbFile, queryFile);
	dbFile.close();
	queryFile.close();

	EXPECT_EQ(true, ret);
}
