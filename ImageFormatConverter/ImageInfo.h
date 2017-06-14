#pragma once
#include <string>
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

