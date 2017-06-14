#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Converter.h"

bool Converter::convert(string image, Type type_in, Type type_out, string new_name)
{
	if (type_in == Type::NONE || type_out == Type::NONE) {
		notSupported();
		return false;
	}
	const char * imageName = image.c_str();
	const char * newName = new_name.c_str();
	int width, height, bpp;
	unsigned char* rgb = stbi_load(imageName, &width, &height, &bpp, 3);
	if (rgb == nullptr) return false;
	int error = 1; //if 0, then error
	switch (type_in) {
		case Type::JPG: {
			switch (type_out) {
				case Type::JPG: printSameTypes(); notSupported(); break;
				case Type::PNG: error = stbi_write_png(newName, width, height, 3, rgb, 0); break; 
				case Type::BMP: error = stbi_write_bmp(newName, width, height, 3, rgb); break; 
				case Type::TGA: error =  stbi_write_tga(newName, width, height, 3, rgb); break; 
				}break; }
		case Type::PNG: {
			switch (type_out) {
				case Type::JPG: notSupported(); break;
				case Type::PNG: printSameTypes(); break;
				case Type::BMP: error = stbi_write_bmp(newName, width, height, 3, rgb); break;
				case Type::TGA: error = stbi_write_tga(newName, width, height, 3, rgb); break;
				}break; }
		case Type::BMP: {
			switch (type_out) {
				case Type::JPG: notSupported(); break;
				case Type::PNG: error = stbi_write_png(newName, width, height, 3, rgb, 0); break;
				case Type::BMP: printSameTypes(); break;
				case Type::TGA: error = stbi_write_tga(newName, width, height, 3, rgb); break;
				}break; }
		case Type::TGA: {
			switch (type_out) {
				case Type::JPG: notSupported(); break;
				case Type::PNG: error = stbi_write_png(newName, width, height, 3, rgb, 0); break;
				case Type::BMP: error = stbi_write_bmp(newName, width, height, 3, rgb); break;
				case Type::TGA: printSameTypes(); break;
				}break; }
		case Type::GIF: {
			switch (type_out) {
			case Type::JPG: notSupported(); break;
			case Type::PNG: error = stbi_write_png(newName, width, height, 3, rgb, 0); break;
			case Type::BMP: error = stbi_write_bmp(newName, width, height, 3, rgb); break;
			case Type::TGA: error = stbi_write_tga(newName, width, height, 3, rgb); break;
			case Type::GIF: printSameTypes(); break;
			}break; }
		case Type::PSD: {
			switch (type_out) {
			case Type::JPG: notSupported(); break;
			case Type::PNG: error = stbi_write_png(newName, width, height, 3, rgb, 0); break;
			case Type::BMP: error = stbi_write_bmp(newName, width, height, 3, rgb); break;
			case Type::TGA: error = stbi_write_tga(newName, width, height, 3, rgb); break;
			case Type::PSD: printSameTypes(); break;
			}break; }
		case Type::PIC: {
			switch (type_out) {
			case Type::JPG: notSupported(); break;
			case Type::PNG: error = stbi_write_png(newName, width, height, 3, rgb, 0); break;
			case Type::BMP: error = stbi_write_bmp(newName, width, height, 3, rgb); break;
			case Type::TGA: error = stbi_write_tga(newName, width, height, 3, rgb); break;
			case Type::PIC: printSameTypes(); break;
			}break; }
	}
	stbi_image_free(rgb);
	return error == 0 ? false : true;
}

	void Converter::printSameTypes()
	{
		cout << endl << "You can't convert to the same type.";
	}

	void Converter::notSupported()
	{
		cout << "Conversion not supported :(" << endl;
		cout << "Supported conversions: ";
		printArray(SUPPORTED_IN_FORMATS);
		cout << " -> ";
		printArray(SUPPORTED_OUT_FORMATS);
		cout << endl;
	}
