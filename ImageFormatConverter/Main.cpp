#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <fstream>
#include <iostream>
#include <string>
#include "stb_image.h"
#include "stb_image_write.h"

using namespace std;

static wchar_t* charToWChar(const char* text)
{
	const size_t size = strlen(text) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, text, size);
	return wText;
}

int main(int argc, char *argv[]) {
	char new_name[100];

	if (argc != 3 && argc != 4) {
		cout << "Correct call: " << argv[0] << " [image_name].[jpg/png/bmp/gif/hdr/psd/pic] [bmp/png/tga] [new_name](optional)";
		return -1;
	}
	else if (argc == 4) {
		strcpy(new_name, argv[3]);
		strcat(new_name, ".");
		strcat(new_name, argv[2]);
	}
	else if (argc == 3) {
		strcpy(new_name, "result");
		strcat(new_name, ".");
		strcat(new_name, argv[2]);
	}
	
		int width, height, bpp;
		unsigned char* rgb = stbi_load(argv[1], &width, &height, &bpp, 3);

		int error = 1;
		string new_format = argv[2];
		if (new_format == "bmp")
			error = stbi_write_bmp(new_name, width, height, 3, rgb);
		else if (new_format == "png")
			error = stbi_write_png(new_name, width, height, 3, rgb, 0);
		else if (new_format == "tga")
			error = stbi_write_tga(new_name, width, height, 3, rgb);

		if (error = 0) cout << "ERROR :(";
		else cout << "SUCCESS! :)";
		stbi_image_free(rgb);

}

