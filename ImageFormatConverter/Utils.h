#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

enum class Type { JPG, PNG, BMP, TGA, HDR, GIF, PSD, PIC, NONE }; //remember to edit toEnumType func

static const vector<string> SUPPORTED_IN_FORMATS = { "jpg", "png", "bmp", "hdr", "gif", "hdr", "psd", "pic" };
static const vector<string> SUPPORTED_OUT_FORMATS = { "bmp", "png", "tga"};

static void printArray(const vector<string> array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i];
		if (i < array.size() - 1) cout << "/";
	}
}

static void toLowerCase(string &str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

static Type toEnumType(string &str)
{
	if (str == "jpg") return Type::JPG;
	if (str == "png") return Type::PNG;
	if (str == "bmp") return Type::BMP;
	if (str == "tga") return Type::TGA;
	if (str == "gif") return Type::GIF;
	if (str == "psd") return Type::PSD;
	if (str == "pic") return Type::PIC;
	return Type::NONE;
}

static bool checkOutType(string type)
{
	if (find(begin(SUPPORTED_OUT_FORMATS), end(SUPPORTED_OUT_FORMATS), type) == end(SUPPORTED_OUT_FORMATS)) return false;
	return true;
}

static bool checkInType(string type)
{
	if (find(begin(SUPPORTED_IN_FORMATS), end(SUPPORTED_IN_FORMATS), type) == end(SUPPORTED_IN_FORMATS)) return false;
	return true;
}


