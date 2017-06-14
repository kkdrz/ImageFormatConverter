#pragma once

#include <string>
#include <iostream>
#include "stb_image.h"
#include "stb_image_write.h"
#include "Utils.h"
using namespace std;

class Converter
{

public:
	bool convert(string image, Type type_in, Type type_out, string new_name);

private:
	void printSameTypes();
	void notSupported();
};

