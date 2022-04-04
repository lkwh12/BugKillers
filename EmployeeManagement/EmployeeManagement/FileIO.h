#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum class FileType {
    INPUT,
    OUTPUT,
    NONE,
};

class FileIO {
public:
    FileIO(const string& fileName, FileType type) :
        fileName_(fileName), type_(type),
        inputFile_(""), outputFile_("") {}
    FileIO(const FileIO& copy) : fileName_(copy.fileName_), type_(copy.type_),
        inputFile_(""), outputFile_("") {}
    
    void open();
    void close();
    vector<string> readLines();
    int writeLines(vector<string> outputs);
    string readLine();
	bool hasMore();
    int writeLine(string output);

private:
	void checkInputOrThrow();
	void checkOutputOrThrow();
    string fileName_;
    FileType type_;
    ifstream inputFile_;
    ofstream outputFile_;
};
