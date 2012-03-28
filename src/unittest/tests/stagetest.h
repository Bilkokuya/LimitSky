#include "gtest\gtest.h"
#include "base\stage.h"

#ifndef TEST_STAGETEST
#define TEST_STAGETEST

#include <cstdlib>

///\brief Tests that the stage is correctly constructed as the default constructor
TEST(Stage, default_constructor)
{
	Stage s = Stage();
	EXPECT_EQ(240, s.width() );
	EXPECT_EQ(180, s.height() );
	EXPECT_EQ(0, s.x() );
	EXPECT_EQ(0, s.y() );
}

///\brief Test for stage initialisation
TEST(Stage, initialisation)
{
}

///\brief Test for stage update of sprite lists and background tiles
TEST(Stage, update)
{
}

///\brief Test to ensure the sprite list is updated and then sent to the OAM correctly
TEST(Stage, update_sprites)
{
}

///\brief Test to ensure the tiles are updated into the background properly
TEST(Stage, update_tiles)
{
}

///\brief Test for stage movement 
TEST(Stage, movement)
{
	Stage s = Stage();
	EXPECT_EQ(0, s.x() );
	EXPECT_EQ(0, s.y() );

	s.moveTo(10,15);
	EXPECT_EQ(10, s.x() );
	EXPECT_EQ(15, s.y() );

	s.move(10,15);
	EXPECT_EQ(20, s.x() );
	EXPECT_EQ(30, s.y() );
}

///\brief Test for stage sizing, ensure that all methods of resizing work properly
TEST(Stage, resizing)
{
	Stage s = Stage();
	EXPECT_EQ(240, s.width() );
	EXPECT_EQ(180, s.height() );

	s.setDimensions(640, 480);
	EXPECT_EQ(640, s.width() );
	EXPECT_EQ(480, s.height() );

	s.width(200);
	s.height(100);
	EXPECT_EQ(200, s.width() );
	EXPECT_EQ(100, s.height() );
}

#endif