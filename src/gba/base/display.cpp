#include "../../../include/base/display.h"
#include "../../../lib/gba/gba.h"

//	Simple background offset modification, to easily add extra backgrounds etc
#define NUM_BACKGROUNDS 4
const int bgOffsets[NUM_BACKGROUNDS][2] = {
	{0,0},
	{0,0},
	{0,3},
	{0,0}
};


Display::Display(int x, int y, int width, int height)
{
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;

	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;

	//	Initialise the GBA's background registers
	for(int i = 0; i < NUM_BACKGROUNDS; ++i)
		backgrounds_[i] = Background(i, bgOffsets[i][0], bgOffsets[i][1]);

	//	Initialise the palette
	SetPaletteBG(0, 0xFF00);
}

void Display::render()
{
	//	Hide all the objects
	for (int i = 0; i < NUM_OBJECTS; ++i)
		SetObject(i, ATTR0_HIDE, 0, 0);

	//	Draw any existing objects
	//	Take sprites from list -> draw them

}

void Display::registerSprite(Sprite* sprite)
{
}