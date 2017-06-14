#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <fstream>
#include <iostream>
#include <string>
#include "stb_image.h"
#include "stb_image_write.h"
#include "IOManager.h"
using namespace std;

static wchar_t* charToWChar(const char* text)
{
	const size_t size = strlen(text) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, text, size);
	return wText;
}

//jpg -> png
//jpg -> bmp
//jpg -> tga
//png -> bmp
//png -> tga
//Converter.exe name.type newType newName
int main(int argc, char *argv[]) {

	IOManager IOManager;
	IOManager.readParams(argc, argv);

	cout << endl << "Name: " << IOManager.getName() << endl;
	cout << "Type: " << IOManager.getType() << endl;
	cout << "New type: " << IOManager.getNewType() << endl;
	cout << "New name: " << IOManager.getNewName() << endl;

	int width, height, bpp;
	unsigned char* rgb = stbi_load(argv[1], &width, &height, &bpp, 3);

	int error = 1;
	string new_format = IOManager.getNewType();
	if (new_format == "bmp")
		error = stbi_write_bmp((IOManager.getNewName() + ".bmp").c_str(), width, height, 3, rgb);
	else if (new_format == "png")
		error = stbi_write_png((IOManager.getNewName()+".png").c_str(), width, height, 3, rgb, 0);
	else if (new_format == "tga")
		error = stbi_write_tga((IOManager.getNewName() + ".tga").c_str(), width, height, 3, rgb);

	if (error = 0) cout << "ERROR :(";
	else cout << "SUCCESS! :)";
	stbi_image_free(rgb);

}

