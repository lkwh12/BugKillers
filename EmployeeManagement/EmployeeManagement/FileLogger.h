#pragma once

#include "ILogger.h"
#include "FileIO.h"

class FileLogger : public ILogger {
public:
	FileLogger(FileIO& file) : ILogger(), file_(file), bPrintDetail(false) { }
	void setPrintDetail(bool option) override {
		bPrintDetail = option;
	}
	int dump(const string& command, const vector<shared_ptr<Employee>>& outputList) override;
private:
	bool bPrintDetail;
	FileIO& file_;
};
