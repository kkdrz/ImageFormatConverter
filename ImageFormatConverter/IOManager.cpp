#include "IOManager.h"
#include <iostream>
using namespace std;

const vector<string> IOManager::SUPPORTED_IN_FORMATS = { "jpg", "png", "bmp", "gif", "hdr", "psd", "pic" };
const vector<string> IOManager::SUPPORTED_OUT_FORMATS = { "bmp", "png", "tga" };

static void printArray(const vector<string> array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i];
		if (i < array.size() - 1) cout << "/";
	}
}

bool IOManager::readParams(int paramsNumber, char *params[])
{
	if (paramsNumber < 3 || paramsNumber > 4) {
		cout << endl << "Wrong number of parameters. There should be 2 or 3 of them." << endl;
		cout << endl << "Correct call: " << params[0] << " [image_name].[";
		printArray(SUPPORTED_IN_FORMATS);
		cout << "] [";
		printArray(SUPPORTED_OUT_FORMATS);
		cout <<"]  [new_name](optional)" << endl;
		return false;
	}
	if (!imageInfo.read(params[1])) {
		cout << endl << "Wrong first parameter. It should be like: imageName.type (i.e image.png)" << endl;
		return false;
	}
	if (!checkInType(imageInfo.getType())) {
		cout << endl << "Wrong image type. Supported in types are: ";
		printArray(SUPPORTED_IN_FORMATS);
		cout << endl;
		return false;
	}
	if (checkOutType(params[2]) == false) {
		cout << endl << "Wrong new type. Supported out types are: ";
		printArray(SUPPORTED_OUT_FORMATS);
		cout << endl;
		return false;
	}
	newType = params[2];
	newName = paramsNumber == 4 ? params[3] : imageInfo.getName();
	return true;
}

string IOManager::getNewType()
{
	return newType;
}

string IOManager::getNewName()
{
	return newName;
}

string IOManager::getName()
{
	return imageInfo.getName();
}

string IOManager::getType()
{
	return imageInfo.getType();
}

bool IOManager::checkOutType(string type)
{
	if (find(begin(SUPPORTED_OUT_FORMATS), end(SUPPORTED_OUT_FORMATS), type) == end(SUPPORTED_OUT_FORMATS)) return false;
	return true;
}

bool IOManager::checkInType(string type)
{
	if (find(begin(SUPPORTED_IN_FORMATS), end(SUPPORTED_IN_FORMATS), type) == end(SUPPORTED_IN_FORMATS)) return false;
	return true;
}

