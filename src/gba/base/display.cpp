#include "../../../include/base/display.h"
#include "../../../lib/gba/gba.h"
#include "../../../resource/tilemaps/tilemaps.h"
#include "../../../resource/tiledata/tiledata.h"

#define MAX_SPRITES 128		//	Maximum number of OAM sprites the GBA can handle on screen at once
#define X_WRAPAROUND 512	//	Value x becomes when wrapping below 0
#define Y_WRAPAROUND 256	//	Value y becomes when wrapping below 0

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

	//	Initialises the main GBA display registers for drawing tiles
	//		(Individual background registers are initialised by the background objects themselves)
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;

	//	Initialise the GBA's background registers
	for(int i = 0; i < NUM_BACKGROUNDS; ++i)
		backgrounds_[i] = Background(i, bgOffsets[i][0], bgOffsets[i][1]);

	//	Initialise the palette
	for (int i = 0; i < PALETTE_LENGTH; ++i){
		SetPaletteBG(i, bgpalette[i]);
	}

	backgrounds_[3].loadTile(0,tileGrass);
	backgrounds_[3].loadTile(1,tileDirt);
	backgrounds_[3].loadTile(2,tileSoil);
	backgrounds_[3].loadTile(3,tileTallGrass);

}

void Display::render()
{
	renderTiles();
	renderSprites();
}

void Display::renderTiles()
{
	int vTiles = (height_ / 8) + 1;	//	Number of vertical tiles
	int hTiles=  (width_ / 8) + 1;
	int xTile = x_ / 8;	//	First tile to start on in the x axis
	int yTile = y_ / 8;

	//	Overwrite the existing tiles for each position (uses less resources than expected)
	for (int y = 0; y < vTiles; ++y){
		for (int x = 0; x < hTiles; ++x){

			int position = ((y+yTile)*MAP_WIDTH) + (x+xTile); // Position of this tile in the tilemap
			backgrounds_[3].setTile( x, y, tilemap_[position]);

		}
	}
}

//	Render all Tiles to the Screen
void Display::renderSprites()
{
	//	Hide all the objects
	for (int i = 0; i < NUM_OBJECTS; ++i)
		SetObject(i, ATTR0_HIDE, 0, 0);

	//	Draw any existing objects, by iterating over the list of sprites
	std::list<Sprite*>::iterator it;
	int nextSprite = 0;	//	Next available sprite index to load up

	for (it = spriteList_.begin(); it != spriteList_.end(); ++it){
		Sprite* sprite = *it;
		//Set the sprite if it is currently on the screen
		if ( (((sprite->x()) + 8) < x_) || (sprite->x() > (x_ + width_)) ) continue;
		if ( (((sprite->y()) + 8) < y_) || (sprite->y() > (y_ + height_)) ) continue;

		int x = sprite->x() - x_;	//	x position to draw to (range 0-> X_WRAPAROUND)
		int y = sprite->y() - y_;	//	y position to draw to (range 0-> Y_WRAPAROUND0

		if (x < 0) x += X_WRAPAROUND;
		if (y < 0) y += Y_WRAPAROUND;

		//	Setup the new object values, to be pushed into VRAM at the end of the frame (not performed by this display)
		SetObject(nextSprite,
			ATTR0_Y( y )	| ATTR0_SHAPE( sprite->shape() )	| ATTR0_8BPP | ATTR0_REG,
			ATTR1_X( x )	| ATTR1_SIZE( sprite->size() ),
			ATTR2_ID( sprite->tile() )	| ATTR2_PRIO( sprite->zPriority() )
			);

		nextSprite++;
		if(nextSprite > MAX_SPRITES) break;
	}
}

void Display::registerSprite(Sprite* sprite)
{
	spriteList_.push_back( sprite );
}

void Display::registerSpriteToFront(Sprite* sprite)
{
	spriteList_.push_front( sprite );
}

int Display::x()
{
	return x_;
}

int Display::y()
{
	return y_;
}

void Display::x(int xPos)
{
	moveTo( xPos, y_);
}

void Display::y(int yPos)
{
	moveTo( x_, yPos);
}

void Display::move(int dx, int dy)
{
	moveTo( (x_ + dx), (y_ + dy) );
}

void Display::moveTo(int x, int y)
{
	x_ = x;
	y_ = y;

	int xOffset = x_%8;
	int yOffset = y_%8;
	for (int i = 0; i < NUM_BACKGROUNDS; ++i){
		backgrounds_[i].moveTo(xOffset, yOffset);
	}
}
