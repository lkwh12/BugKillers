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

	Parser parser;
	MemoryDatabase memDB;
	IDatabase& DB = memDB;
	CommandFactory commandFactory;

	while (1) {
		string inputLine = inputFile.readLine();
		if (inputLine == "") break;
		Input input = parser.parseLine(inputLine);
		shared_ptr<ICommand> cmd = commandFactory.createCommand(input);
		//cmd->execute();
	}

	inputFile.close ();
	outputFile.close();
	return 0;
}
