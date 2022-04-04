#pragma once
#include <vector>
#include <string>


class Input {
	using Payload = std::vector<std::string>;
public:
	Input() {}
	Input(const std::string& command,
		const std::string& firstOption,
		const std::string& secondOption,
		const Payload& payload
	) : command(command), firstOption(firstOption), secondOption(secondOption), payload(payload){ }

	const std::string& getCommand() const { return this->command; }
	const std::string& getFirstOption() const { return this->firstOption; }
	const std::string& getSecondOption() const { return this->secondOption; }
	const Payload& getPayload() const { return this->payload; }
private:
	std::string command;
	std::string firstOption;
	std::string secondOption;
	Payload payload;
};
