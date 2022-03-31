#include <iostream>
#include "FileIO.h"

int main(int argc, char** argv) {
	FileIO inputFile(argv[1], FileType::INPUT);
	FileIO outputFile(argv[2], FileType::OUTPUT);
	inputFile.open();
	outputFile.open();

	inputFile.close ();
	outputFile.close();
	return 0;
}