#include "Converter.h"

bool Converter::convert(string image, Type type_in, Type type_out)
{
	//if (type_in == Type::NONE || type_out == Type::NONE) return false;
	//const char * imageName = image.c_str();
	//int width, height, bpp;
	//unsigned char* rgb = stbi_load(imageName, &width, &height, &bpp, 3);
	int error = 1; //if 0, then error
	//switch (type_in) {
	//	case Type::JPG: {
	//		switch (type_out) {
	//			case Type::JPG: printSameTypes(); break;
	//			case Type::PNG: error = stbi_write_png(imageName, width, height, 3, rgb, 0); break;
	//			case Type::BMP: error = stbi_write_bmp(imageName, width, height, 3, rgb); break;
	//			case Type::TGA: error = stbi_write_tga(imageName, width, height, 3, rgb); break;
	//			}break; }
	//	case Type::PNG: {
	//		switch (type_out) {
	//			case Type::JPG: break;
	//			case Type::PNG: printSameTypes(); break;
	//			case Type::BMP: error = stbi_write_bmp(imageName, width, height, 3, rgb); break;
	//			case Type::TGA: error = stbi_write_tga(imageName, width, height, 3, rgb); break;
	//			}break; }
	//	case Type::BMP: {
	//		switch (type_out) {
	//			case Type::JPG: break;
	//			case Type::PNG: error = stbi_write_png(imageName, width, height, 3, rgb, 0); break;
	//			case Type::BMP: printSameTypes(); break;
	//			case Type::TGA: error = stbi_write_tga(imageName, width, height, 3, rgb); break;
	//			}break; }
	//	case Type::TGA: {
	//		switch (type_out) {
	//			case Type::JPG: break;
	//			case Type::PNG: error = stbi_write_png(imageName, width, height, 3, rgb, 0); break;
	//			case Type::BMP: error = stbi_write_bmp(imageName, width, height, 3, rgb); break;
	//			case Type::TGA: printSameTypes(); break;
	//			}break; }
	//}
	//stbi_image_free(rgb);
	return error == 0 ? false : true;
}

	void Converter::printSameTypes()
	{
		cout << endl << "You can't convert to the same type.";
	}
