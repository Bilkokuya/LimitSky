//	The display manager

#ifndef LS_DISPLAY
#define LS_DISPLAY

#include "sprite.h"
#include "background.h"

class Display
{
public:
	Display(int x, int y, int width, int height);

	void render();

	void registerSprite(Sprite* sprite);

private:
	int x_, y_, width_, height_;
	Background backgrounds_[4];
	//Spritelist
	//Tilemaps

};

#endif