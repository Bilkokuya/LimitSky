#include "engine\engine.h"
#include "engine\platform.h"
#include "engine\sprite.h"

Platform platform;

void setPlatform(Platform p)
{
	platform = p;
}

void registerSprite(Sprite s)
{
	platform.registerSprite(s);
}