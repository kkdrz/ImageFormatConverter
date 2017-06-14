#pragma once
#include "ImageInfo.h"
#include <iostream>
#include <string>
#include "Utils.h"
#include <vector>
#include "Converter.h"

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
	string getNameWithNewType();

private:
	ImageInfo imageInfo;
	string newType;
	string newName;
};

