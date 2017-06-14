#pragma once
#include "ImageInfo.h"
#include <string>
#include <vector>

class IOManager
{	

public:
	
	bool readParams(int paramsNumber, char *params[]);
	static const vector<string> SUPPORTED_IN_FORMATS;
	static const vector<string> SUPPORTED_OUT_FORMATS;
	string getNewType();
	string getNewName();
	string getName();
	string getType();

private:
	bool checkOutType(string type);
	bool checkInType(string type);
	ImageInfo imageInfo;
	string newType;
	string newName;
};

