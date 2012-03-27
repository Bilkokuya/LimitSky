#include "gtest\gtest.h"
#include "common\stage.h"

#ifndef TEST_STAGETEST
#define TEST_STAGETEST

#include <cstdlib>

///\brief Tests that the stage properly constructs the sprites array as an array of Sprite*
TEST(Stage, Constructor)
{
	Stage s = Stage();
	Sprite** sprites = s.sprites();
}

///\brief Tests that the stage properly destructs the sprites array and that no memory is leaked
TEST(Stage, Destructor)
{
}

#endif