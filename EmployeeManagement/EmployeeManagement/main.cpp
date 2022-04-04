#include <iostream>
#include <memory>
#include "FileIO.h"
#include "Parser.h"
#include "CommandFactory.h"
#include "MemoryDatabase.h"
#include "FileLogger.h"

void printHelp() {
	cout << " usage:" << endl
		 << "    EmployeeManagement.exe input_file_name output_file_name" << endl;
}

class EmployeeManagement {
public:
	EmployeeManagement() { }

	~EmployeeManagement() {
		if (!isPrepared) return;
		fileIn_->close();
		fileOut_->close();
	}

	void prepare(const string& inFile, const string& outFile) {
		isPrepared = true;
		db_ = make_shared<MemoryDatabase>();
		fileIn_ = make_unique<FileIO>(inFile, FileType::INPUT);
		fileOut_ = make_shared<FileIO>(outFile, FileType::OUTPUT);
		fileIn_->open();
		fileOut_->open();
		logger_ = make_shared<FileLogger>(fileOut_);
	}

	void proceed() {
		Parser parser;
		CommandFactory commandFactory;
		while (fileIn_->hasMore()) {
			Input input = parser.parseLine(fileIn_->readLine());
			bool doPrintDetail = input.getFirstOption() == "-p";
			logger_->setPrintDetail(doPrintDetail);
			shared_ptr<ICommand> cmd = commandFactory.createCommand(input);
			cmd->execute(*db_, *logger_);
		}
	}

private:
	bool isPrepared = false;
	shared_ptr<IDatabase> db_;
	unique_ptr<FileIO> fileIn_;
	shared_ptr<FileIO> fileOut_;
	shared_ptr<ILogger> logger_;
};

int main(int argc, char** argv) {
	if (argc < 3) {
		printHelp();
		return -1;
	}

	EmployeeManagement mgr;
	auto inputFileName = argv[1];
	auto outputFileName = argv[2];
	mgr.prepare(inputFileName, outputFileName);
	mgr.proceed();

	return 0;
}
