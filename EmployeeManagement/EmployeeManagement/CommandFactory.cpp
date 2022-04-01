#include "CommandFactory.h"

ICommand* CommandFactory::createCommand(string command) {
	if (command == "ADD") {
		ICommand* result = nullptr; // new AddCommand
		return result;
	}
	else if (command == "DEL") {
		ICommand* result = nullptr; // new DelCommand
		return result;
	}
	else if (command == "MOD") {
		ICommand* result = nullptr; // new ModCommand
		return result;
	}
	else if (command == "SCH") {
		ICommand* result = nullptr; // new SchCommand
		return result;
	}
	else {
		throw invalid_argument("ERR: Invalid Command Type");
	}
}