#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

enum class Type { JPG, PNG, BMP, TGA, NONE };

const vector<string> SUPPORTED_IN_FORMATS = { "jpg", "png", "bmp", "gif", "hdr", "psd", "pic" };
const vector<string> SUPPORTED_OUT_FORMATS = { "bmp", "png", "tga" };

void printArray(const vector<string> array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i];
		if (i < array.size() - 1) cout << "/";
	}
}

void toLowerCase(string &str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

Type toEnumType(string &str)
{
	if (str == "jpg") return Type::JPG;
	if (str == "png") return Type::PNG;
	if (str == "bmp") return Type::BMP;
	if (str == "tga") return Type::TGA;
	return Type::NONE;
}

bool checkOutType(string type)
{
	if (find(begin(SUPPORTED_OUT_FORMATS), end(SUPPORTED_OUT_FORMATS), type) == end(SUPPORTED_OUT_FORMATS)) return false;
	return true;
}

bool checkInType(string type)
{
	if (find(begin(SUPPORTED_IN_FORMATS), end(SUPPORTED_IN_FORMATS), type) == end(SUPPORTED_IN_FORMATS)) return false;
	return true;
}


