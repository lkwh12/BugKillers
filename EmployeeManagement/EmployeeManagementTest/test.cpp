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

TEST(TestCaseName, FullScenarioTest) {
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
