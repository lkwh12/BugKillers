#include "FileIO.h"

void FileIO::open() {
	switch(type_) {
	case FileType::INPUT:
		inputFile_.open(fileName_);
		return;
	case FileType::OUTPUT:
		outputFile_.open(fileName_);
		return;
	default:
		throw invalid_argument("ERR: Unknown File Type");
	}
}
void FileIO::close() {
	switch (type_) {
	case FileType::INPUT:
		inputFile_.close();
		return;
	case FileType::OUTPUT:
		outputFile_.close();
		return;
	default:
		throw invalid_argument("ERR: Unknown File Type");
	}
}
vector<string> FileIO::readLines() {
	checkInputOrThrow();
	vector<string> result;
	while (!inputFile_.eof()) {
		result.emplace_back();
		getline(inputFile_, result.back());
	}
	return result;
}
int FileIO::writeLines(vector<string> outputs) {
	checkOutputOrThrow();
	int numLines = 0;
	for(auto line: outputs) {
		outputFile_ << line << endl;
		numLines++;
	}
	return numLines;
}
string& FileIO::readLine() {
	checkInputOrThrow();
	// not thread-safe
	static string result;
	if (inputFile_.eof()) {
		return result;
	}
	getline(inputFile_, result);
	return result;
}
bool FileIO::hasMore() {
	checkInputOrThrow();
	return !inputFile_.eof();
}
int FileIO::writeLine(string output) {
	checkOutputOrThrow();
	outputFile_ << output << endl;
	return 1;
}
void FileIO::checkInputOrThrow() {
	if (!inputFile_.is_open()) {
		throw invalid_argument("ERR: Input File is NOT opened");
	}
}
void FileIO::checkOutputOrThrow() {
	if (!outputFile_.is_open()) {
		throw invalid_argument("ERR: Output File is NOT opened");
	}
}
