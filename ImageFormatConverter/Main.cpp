#include <fstream>
#include <iostream>
#include <string>
#include <Magick++.h>

using namespace std;

static wchar_t* charToWChar(const char* text)
{
	const size_t size = strlen(text) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, text, size);
	return wText;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		
		cout << "Correct call: " << argv[0] << " [image_name].[jpg/png/bmp] [jpg/bmp/png/jpe]";
		int a;
		cin >> a;
	}
	else {
			cout << "arg[1] = " << argv[1] << endl;
			cout << "arg[2] = " << argv[2] << endl;
			string image_path = argv[1];
			string image_name = image_path.substr(0, image_path.find("."));
			string image_format = image_path.substr(image_path.find(".") + 1, image_path.length() - image_path.find("."));
			

			cout << "path: " << image_path << endl;
			cout << "name: " << image_name << endl;
			cout << "format: " << image_format << endl;

			int a;
			cin >> a;
		}

}
