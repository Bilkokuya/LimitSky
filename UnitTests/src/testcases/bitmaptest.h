#define ENABLEINTELLISENSE
#undef ENABLEINTELLISENSE

#ifndef TEST_BITMAPTEST
#define TEST_BITMAPTEST

#include "engine\bitmap.h"
#include <cstdlib>

///\brief Tests to ensure the Bitmap default constructor works correctly.
///		Checks both for a single instance and for array intialisation
TEST(Bitmap,empty_constructor)
{
	//	Check empty consutructor assigns correctly
	Bitmap<unsigned char> b = Bitmap<unsigned char>();
	EXPECT_EQ(NULL, b.bitmapData());
	EXPECT_EQ(0, b.width());
	EXPECT_EQ(0, b.height());

	//	Check array instantiates Bitmap correctly
	Bitmap<unsigned char> bitmaps[5];
	EXPECT_EQ(NULL, bitmaps[3].bitmapData());
	EXPECT_EQ(0, bitmaps[3].width());
	EXPECT_EQ(0, bitmaps[3].height());
}

///\brief Tests to ensure the Bitmap standard constructor works properly
///		Ensures all member variables are instantiated properly, includeing the bitmapData pointer
TEST(Bitmap,constructor)
{
	unsigned char data = 5;

	//	Check array instantiates Bitmap correctly
	Bitmap<unsigned char> bitmap = Bitmap<unsigned char>(&data,10,7);
	
	EXPECT_EQ(10, bitmap.width() );
	EXPECT_EQ(7, bitmap.height() );

	//	Ensure the bitmapData pointer is correct
	unsigned char* p = bitmap.bitmapData();
	unsigned char pvalue = *p;
	EXPECT_EQ(data, pvalue);
	EXPECT_EQ(&data, bitmap.bitmapData() );
}

#endif