//	Visual Studio hack for Intellisense
#define ENABLEINTELLISENSE
#undef	ENABLEINTELLISENSE

#ifndef LS_BITMAP
#define LS_BITMAP

///\brief	Bitmap Resource, comprising of non-platform specific bitmapData, and size data.
///				On the GBA, the sizes are specifically limited to 8x8 amounts, as this is tile data
///\param T The type of bitmapData to be used. On the GBA this is uint8_t (unsigned char), due to indexed pixels
template <class T> 
class Bitmap
{
public:

	///\brief Default Constructor for array initialisation
	Bitmap();	

	///\brief Usable constructor for majority of cases
	///\param bitmapData Initialises the pointer to the bitmap data to be used
	///\param width Initialises the width of this bitmap in pixels
	///\param height Initialises the height of this bitmap in pixels
	Bitmap(T* bitmapData, int width, int height);	


	///\brief Getter: Gets the width of this bitmap
	///\return The width of this bitmap in pixels
	int width();	

	///\brief Getter: Gets the height of this bitmap
	///\return The height of this bitmap in pixels
	int height();	

	///\brief Setter: Sets the width of this bitmap
	///\param w The new width of this bitmap in pixels
	void width(int w);

	///\brief Setter: Sets the height of this bitmap
	///\param h The new height of this bitmap in pixels
	void height(int h);	

	///\brief Getter: Gets the bitmapData pointer
	///\return A pointer to the bitmap data
	T* bitmapData();

	///\brief Setter: Sets the pointer to the bitmapData
	///		On the GBA, this is the pointer to a const uint8_t array of indexed colours
	///\param T* Sets the bitmapdata of this bitmap
	void bitmapData(T* data);	

private:
	int width_		///< The width of this resource in pixels.
	int height_;	///< The height of this resource in pixels.
	T* bitmapData_;	///< A pointer to the bitmap data for this bitmap resource.
};

#endif