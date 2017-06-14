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
	string getNewType();
	string getNewName();
	string getName();
	string getType();
	string getNewNameWithNewType();
	string getNameWithType();

private:
	ImageInfo imageInfo;
	string newType;
	string newName;
};

