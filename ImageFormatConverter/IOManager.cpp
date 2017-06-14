#include "IOManager.h"

using namespace std;

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
	toLowerCase(newType);
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

string IOManager::getNameWithNewType()
{
	return newName + "." + newType;
}






