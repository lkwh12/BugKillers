#include "CommandFactory.h"

shared_ptr<ICommand> CommandFactory::createCommand(Input input) {
	if (input.getCommand() == "ADD") {
		shared_ptr<ICommand> result = nullptr; // new AddCommand(input)
		return result;
	}
	else if (input.getCommand() == "DEL") {
		shared_ptr<ICommand> result = nullptr; // new DelCommand(input)
		return result;
	}
	else if (input.getCommand() == "MOD") {
		shared_ptr<ICommand> result = nullptr; // new ModCommand(input)
		return result;
	}
	else if (input.getCommand() == "SCH") {
		shared_ptr<ICommand> result = nullptr; // new SchCommand(input)
		return result;
	}
	else {
		throw invalid_argument("ERR: Invalid Command Type");
	}
}