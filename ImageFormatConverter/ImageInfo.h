#pragma once
#include <string>
#include "Utils.h"
using namespace std;

class ImageInfo
{
public:
	ImageInfo();
	~ImageInfo();
	bool read(string name);
	string getName();
	string getType();

private:
	string name;
	string type;

};

