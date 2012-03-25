#include "engine\bitmap.h"
#include <cstdlib>

//	Default constructor, mainly for array use
//	Ensures member variables are initialised and the bitmapData is a null pointer
Bitmap::Bitmap()
{
	width_ = 0;
	height_ = 0;
}

//	Main constructor for the majority of uses, initialises everything as required
//	TODO: register with the engine
Bitmap::Bitmap( int width, int height)
{
	width_ = width;
	height_ = height;
}

//	Getter for the width
int Bitmap::width()
{
	return width_;
}

//	Setter for the width
void Bitmap::width(int w)
{
	width_ = w;
}

//	Getter for the height
int Bitmap::height()
{
	return height_;
}

//	Setter for the height
void Bitmap::height(int h)
{
	height_ = h;
}





