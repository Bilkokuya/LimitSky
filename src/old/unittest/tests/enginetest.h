#ifndef TEST_ENGINETEST
#define TEST_ENGINETEST

#include "engine\sprite.h"
#include "engine\engine.h"
#include "engine\displaylist.h"

///\brief Test to ensure new sprites are added to the engine Sprite list
TEST(Engine,Add_Remove_Sprite)
{
	//	Test Adding a new Sprite automatically
	Sprite s = Sprite(10, 7, 180, 1, 2);
	EXPECT_EQ(1, displayList.spriteList.size() );

	//	Adding a sprite manually
	Sprite s2 = Sprite();
	//	Check that default constructor does not add one
	EXPECT_EQ(1, displayList.spriteList.size() );
	//	Check adding one manually does add one
	displayList.addSprite(&s2);
	EXPECT_EQ(2, displayList.spriteList.size() );
	

	//	Removing a previously added Sprite
	displayList.removeSprite(&s);
	EXPECT_EQ(1, displayList.spriteList.size() );

}

#endif