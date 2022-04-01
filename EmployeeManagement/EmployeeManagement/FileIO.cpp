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
	if (!inputFile_.is_open()) {
		throw invalid_argument("ERR: Input File is NOT opened");
	}
	vector<string> result;
	while (!inputFile_.eof()) {
		result.emplace_back();
		getline(inputFile_, result.back());
	}
	return result;
}
int FileIO::writeLines(vector<string> outputs) {
	int numLines = 0;
	if (!outputFile_.is_open()) {
		throw invalid_argument("ERR: Output File is NOT opened");
	}
	for(auto line: outputs) {
		outputFile_ << line << endl;
		numLines++;
	}
	return numLines;
}
string FileIO::readLine() {
	string result;
	if (!inputFile_.is_open()) {
		throw invalid_argument("ERR: Input File is NOT opened");
	}
	if (inputFile_.eof()) {
		return result;
	}
	getline(inputFile_, result);
	return result;
}
int FileIO::writeLine(string output) {
	if (!outputFile_.is_open()) {
		throw invalid_argument("ERR: Output File is NOT opened");
	}
	outputFile_ << output << endl;
	return 1;
}
