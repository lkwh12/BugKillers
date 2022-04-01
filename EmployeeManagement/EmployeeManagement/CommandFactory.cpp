#include "CommandFactory.h"

shared_ptr<ICommand> CommandFactory::createCommand(string command) {
	if (command == "ADD") {
		shared_ptr<ICommand> result = nullptr; // new AddCommand
		return result;
	}
	else if (command == "DEL") {
		shared_ptr<ICommand> result = nullptr; // new DelCommand
		return result;
	}
	else if (command == "MOD") {
		shared_ptr<ICommand> result = nullptr; // new ModCommand
		return result;
	}
	else if (command == "SCH") {
		shared_ptr<ICommand> result = nullptr; // new SchCommand
		return result;
	}
	else {
		throw invalid_argument("ERR: Invalid Command Type");
	}
}