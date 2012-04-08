#include "../../include/tilemap.h"

#define NULL 0

Tilemap::Tilemap()
{
	tiledata_ = NULL;
}

Tilemap::Tilemap(const unsigned char* tiledata, int width, int height)
{
	tiledata_ = tiledata;
	width_ = width;
	height_ = height;
}

unsigned char Tilemap::getTileAt(int x, int y)
{
	return (getTileAt( (y*width_) + x) );
}

unsigned char Tilemap::getTileAt(int index)
{
	return tiledata_[index];
}

