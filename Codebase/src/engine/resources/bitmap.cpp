#include "engine\bitmap.h"
#include <cstdlib>

template class Bitmap<unsigned char>;

//	Default constructor, mainly for array use
//	Ensures member variables are initialised and the bitmapData is a null pointer
template <class T>
Bitmap<T>::Bitmap()
{
	width_ = 0;
	height_ = 0;
	bitmapData_ = NULL;
}

//	Main constructor for the majority of uses, initialises everything as required
//	TODO: register with the engine
template <class T>
Bitmap<T>::Bitmap(T* bitmapData, int width, int height)
{
	width_ = width;
	height_ = height;
	bitmapData_ = bitmapData;
}

//	Getter for the width
template <class T>
int Bitmap<T>::width()
{
	return width_;
}

//	Setter for the width
template <class T>
void Bitmap<T>::width(int w)
{
	width_ = w;
}

//	Getter for the height
template <class T>
int Bitmap<T>::height()
{
	return height_;
}

//	Setter for the height
template <class T>
void Bitmap<T>::height(int h)
{
	height_ = h;
}

//	Getter for the bitmapData
template <class T>
T* Bitmap<T>::bitmapData()
{
	return bitmapData_;
}

//	Setter for the bitmapData pointer
template <class T>
void Bitmap<T>::bitmapData(T* data)
{
	bitmapData_ = data;
}




