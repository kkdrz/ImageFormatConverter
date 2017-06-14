
#include <fstream>
#include <iostream>
#include <string>
#include "Utils.h"
#include "IOManager.h"
#include "Converter.h"
using namespace std;

static wchar_t* charToWChar(const char* text)
{
	const size_t size = strlen(text) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, text, size);
	return wText;
}


//Converter.exe name.type newType newName
int main(int argc, char *argv[]) {

	IOManager IOManager;
	Converter converter;
	IOManager.readParams(argc, argv);
	bool error = converter.convert(IOManager.getNameWithType(), toEnumType(IOManager.getType()), toEnumType(IOManager.getNewType()), IOManager.getNewNameWithNewType());

	if (error) cout << "SUCCESS :)";
	else cout << "ERROR :( Check if the file exists!";
	
}

