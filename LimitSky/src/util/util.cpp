//	Copyright 2012 Gordon D Mckendrick
//	Author: Gordon D Mckendrick
//
//	Util
//		Utility functions used throughout the game

#include "util.h"
#include "../lib/gba.h"

//	Returns true if the given key is pressed
bool isKeyDown(int key)
{
	return ((REG_P1 & key) == 0);
}
