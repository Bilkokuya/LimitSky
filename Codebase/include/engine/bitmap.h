//	Visual Studio hack for Intellisense
#define ENABLEINTELLISENSE
#undef	ENABLEINTELLISENSE

#ifndef LS_BITMAP
#define LS_BITMAP

///\brief	Bitmap Resource, comprising of non-platform specific bitmapData, and size data.
///				On the GBA, the sizes are specifically limited to 8x8 amounts, as this is tile data
///\param T The type of bitmapData to be used. On the GBA this is uint8_t (unsigned char), due to indexed pixels
class Bitmap <T>
{
public:
	Bitmap();	///<\brief Default Constructor for array initialisation
	Bitmap(T* bitmapData, int width, int height);	///\brief Usable constructor for majority of cases

	int width();	///<\return int The width of this bitmap in pixels
	int height();	///<\return int The height of this bitmap in pixels

	void width(int w);	///<\param w Set the width of this bitmap in pixels
	void height(int h);	///<\param h Set the height of this bitmap in pixels

	T* bitmapData();			///<\return T* The pointer to the bitmap data
	void bitmapData(T* data);	///\param T* Sets the bitmapdata of this bitmap

private:
	int width_, height_;	///<	The width and height of this resource in pixels.
	T* bitmapData_;			///<	A pointer to the bitmap data for this bitmap resource.
};

#endif