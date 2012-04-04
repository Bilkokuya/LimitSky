#include "../../../include/base/display.h"
#include "../../../lib/gba/gba.h"
#include "../../../resource/tilemaps/tilemaps.h"

//	Maximum number of OAM sprites the GBA can handle on screen at once
#define MAX_SPRITES 128

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
	tilemap_ = testTilemap;

	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;

	//	Initialise the GBA's background registers
	for(int i = 0; i < NUM_BACKGROUNDS; ++i)
		backgrounds_[i] = Background(i, bgOffsets[i][0], bgOffsets[i][1]);

	//	Initialise the palette
	SetPaletteBG(0, 0xFF00);
}

//	Render all Tiles to the Screen
void Display::render()
{
	//	Hide all the objects
	for (int i = 0; i < NUM_OBJECTS; ++i)
		SetObject(i, ATTR0_HIDE, 0, 0);

	//	Draw any existing objects, by iterating over the list of sprites
	std::list<Sprite*>::iterator it;
	int nextSprite = 0;	//	Next available sprite index to load up

	for (it = spriteList_.begin(); it != spriteList_.end(); ++it){
		Sprite* s = *it;
		//Set the sprite if it is currently on the screen
		if ( (((s->x()) + 8) < x_) || (s->x() > (x_ + width_)) ) continue;
		if ( (((s->y()) + 8) < y_) || (s->y() > (y_ + height_)) ) continue;

		int x = s->x() - x_;
		int y = s->y() - y_;

		if (x < 0) x += 512;
		if (y < 0) y += 256;

		SetObject(nextSprite,
			ATTR0_Y( y )	| ATTR0_SHAPE( s->shape() )	| ATTR0_8BPP | ATTR0_REG,
			ATTR1_X( x )	| ATTR1_SIZE( s->size() ),
			ATTR2_ID( s->tile() )	| ATTR2_PRIO( s->zPriority() )
			);

		nextSprite++;
		if(nextSprite > MAX_SPRITES) break;
	}



}

void Display::registerSprite(Sprite* sprite)
{
	spriteList_.push_back( sprite );
}
