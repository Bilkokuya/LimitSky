#ifndef TEST_SPRITETEST
#define	TEST_SPRITETEST

#include "gtest\gtest.h"
#include "base\sprite.h"

///\brief Test to ensure the Sprite constructor functions correctly
///		Loads in a simple constructor and checks member variable values
TEST(Sprite,default_constructor)
{
	Sprite s = Sprite();
	EXPECT_EQ(0,s.x());
	EXPECT_EQ(0,s.y());
	EXPECT_EQ(0,s.rotation());
	EXPECT_EQ(1,s.scaleX());
	EXPECT_EQ(1,s.scaleY());
}

///\brief Test to ensure the Sprite constructor functions correctly
///		Loads in a simple constructor and checks member variable values
TEST(Sprite,constructor)
{
	Sprite s = Sprite(10, 7, 180, 1, 2);
	EXPECT_EQ(10,s.x());
	EXPECT_EQ(7,s.y());
	EXPECT_EQ(180,s.rotation());
	EXPECT_EQ(1,s.scaleX());
	EXPECT_EQ(2,s.scaleY());
}

///\brief Test to ensure Sprite movement works correctly
///		Moves the Sprite using the various methods and checks position at each point
TEST(Sprite,movement)
{
	Sprite s = Sprite(10, 7, 180, 1, 2);
	EXPECT_EQ(10, s.x());
	EXPECT_EQ(7, s.y());

	s.moveTo(5,10);
	EXPECT_EQ(5, s.x());
	EXPECT_EQ(10, s.y());

	s.move(5,-5);
	EXPECT_EQ(10, s.x());
	EXPECT_EQ(5, s.y());

	s.x(20);
	s.y(50);
	EXPECT_EQ(20, s.x());
	EXPECT_EQ(50, s.y());
}

///\brief Test to ensure Sprite rotation works correctly
///		Rotates the Sprite using the various methods and checks rotation wraps correctly
TEST(Sprite,rotation)
{
	Sprite s = Sprite(10, 7, 180, 1, 2);
	EXPECT_EQ(180, s.rotation());

	s.rotation(45);
	EXPECT_EQ(45, s.rotation());

	s.rotate(45);
	EXPECT_EQ(90, s.rotation());

	s.rotate(-120);
	EXPECT_EQ(330, s.rotation());
}

///\brief Test to ensure Sprite scaling works correctly
///		Scales the sprite using the various methods and ensures the correct scale is achieved each time
TEST(Sprite,scaling)
{
	Sprite s = Sprite(10, 7, 180, 1, 2);
	EXPECT_EQ(1, s.scaleX());
	EXPECT_EQ(2, s.scaleY());

	s.scaleTo(4,5);
	EXPECT_EQ(4, s.scaleX());
	EXPECT_EQ(5, s.scaleY());

	s.scale(2,2);
	EXPECT_EQ(8,s.scaleX());
	EXPECT_EQ(10,s.scaleY());

	s.scaleX(5);
	s.scaleY(3);
	EXPECT_EQ(5,s.scaleX());
	EXPECT_EQ(3,s.scaleY());
}

#endif