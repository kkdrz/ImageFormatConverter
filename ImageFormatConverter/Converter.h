#pragma once
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <string>
#include <iostream>
//#include "stb_image.h"
//#include "stb_image_write.h"
#include "Utils.h"
using namespace std;

class Converter
{

public:
	bool convert(string image, Type type_in, Type type_out);

private:
	void printSameTypes();
};

