#include "ImageInfo.h"



ImageInfo::ImageInfo()
{
}


ImageInfo::~ImageInfo()
{
}

bool ImageInfo::read(string image_path)
{
	if (image_path.find(".") == string::npos) return false;
	name = image_path.substr(0, image_path.find("."));
	type = image_path.substr(image_path.find(".") + 1, image_path.length() - image_path.find("."));
	toLowerCase(type);
	if (!checkInType(type) || name.size() < 1) return false;
	return true;
}

string ImageInfo::getName()
{
	return name;
}

string ImageInfo::getType()
{
	return type;
}
