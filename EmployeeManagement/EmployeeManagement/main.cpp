#include <iostream>
#include "FileIO.h"
#include "Parser.h"
#include "CommandFactory.h"
#include "MemoryDatabase.h"

int main(int argc, char** argv) {
	FileIO inputFile(argv[1], FileType::INPUT);
	FileIO outputFile(argv[2], FileType::OUTPUT);
	inputFile.open();
	outputFile.open();

	Parser* pParser = new Parser();
	IDatabase* pDatabase = new MemoryDatabase();
	CommandFactory* pCommandFactory = new CommandFactory();

	while (1) {
		string inputLine = inputFile.readLine();
		if (inputLine == "") break;
		Input input = pParser->parseLine(inputLine);
		ICommand* cmd = pCommandFactory->createCommand(input.getCommand());
		//cmd->execute();
	}

	inputFile.close ();
	outputFile.close();
	delete pCommandFactory;
	delete pDatabase;
	delete pParser;
	return 0;
}
