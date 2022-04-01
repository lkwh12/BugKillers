#pragma once
#include "Interface.h"
#include "FileIO.h"

interface ILogger {
	virtual void setOutFile(const FileIO& file) = 0;
	virtual void dump() = 0; // TODO: redefine
};
