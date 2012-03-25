#include <iostream>
#include "gtest/gtest.h"

#include "testcases\engine\enginetest.h"
#include "testcases\engine\spritetest.h"
#include "testcases\engine\bitmaptest.h"

int main(int argc, char** argv) 
{ 
    testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS(); 
    std::getchar(); // keep console window open until Return keystroke
}

//	Ensures the test rig is functional by testing for simple additional equalities
TEST(gTest,equality)
{
	int i = 5;
	EXPECT_EQ(5,i);
	EXPECT_EQ(6,++i);
	i += 4;
	EXPECT_EQ(10, i);
}
