#ifndef GBA_PLATFORM
#define GBA_PLATFORM
#include "engine\platform.h"

class GBAPlatform: public Platform
{
	void registerSprite(Sprite s);
};

#endif