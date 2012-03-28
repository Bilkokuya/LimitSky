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
	Bitmap b = Bitmap();
	EXPECT_EQ(0, b.width());
	EXPECT_EQ(0, b.height());

	//	Check array instantiates Bitmap correctly
	Bitmap bitmaps[5];
	EXPECT_EQ(0, bitmaps[3].width());
	EXPECT_EQ(0, bitmaps[3].height());
}

///\brief Tests to ensure the Bitmap standard constructor works properly
///		Ensures all member variables are instantiated properly, includeing the bitmapData pointer
TEST(Bitmap,constructor)
{
	//	Check array instantiates Bitmap correctly
	Bitmap bitmap = Bitmap(10,7);
	
	EXPECT_EQ(10, bitmap.width() );
	EXPECT_EQ(7, bitmap.height() );
}

#endif