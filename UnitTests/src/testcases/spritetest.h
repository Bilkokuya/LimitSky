#ifndef TEST_SPRITETEST
#define	TEST_SPRITETEST

#include "engine\sprite.h"


TEST(Sprite,constructor)
{
	Sprite s = Sprite(10, 7, 180, 1, 2);
	EXPECT_EQ(10,s.x());
	EXPECT_EQ(7,s.y());
	EXPECT_EQ(180,s.rotation());
	EXPECT_EQ(1,s.scaleX());
	EXPECT_EQ(2,s.scaleY());
}

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