#include "../../include/display.h"
#include "../../lib/gba/gba.h"
#include "../../resource/tilemaps/tilemaps.h"
#include "../../resource/tiledata/tiledata.h"
#include "../../include/block.h"
#include "../../include/blockmap.h"

#define MAX_SPRITES 128		//	Maximum number of OAM sprites the GBA can handle on screen at once
#define X_WRAPAROUND 512	//	Value x becomes when wrapping below 0
#define Y_WRAPAROUND 256	//	Value y becomes when wrapping below 0
#define XTILES 30
#define YTILES 24

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
	tilemap_ = worldTilemap;
	blockMap_ = BlockMap(worldMap);


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


	int nextTile = 10;

	for (int i = 0; i < 4; ++i){
		
		grass.isLoaded_[3] = true;
		grass.loadedIndex_[3][i] = nextTile;
		backgrounds_[3].loadTile(grass.loadedIndex_[3][i],grass.tileData_[i]);
		nextTile++;
	}
	for (int i = 0; i < 4; ++i){
		
		soil.isLoaded_[3] = true;
		soil.loadedIndex_[3][i] = nextTile;
		backgrounds_[3].loadTile(soil.loadedIndex_[3][i],soil.tileData_[i]);
		nextTile++;
	}
	for (int i = 0; i < 4; ++i){
		
		dirt.isLoaded_[3] = true;
		dirt.loadedIndex_[3][i] = nextTile;
		backgrounds_[3].loadTile(dirt.loadedIndex_[3][i],dirt.tileData_[i]);
		nextTile++;
	}

}

void Display::render()
{
	renderTiles();
	renderSprites();
}

void Display::renderTiles()
{
	int hBlocks = (width_ / 16) + 1;	//	Number of horizontal tiles
	int vBlocks = (height_ / 16) + 1;	
	int xBlock = x_ / 16;	//	First tile to start on in the x axis
	int yBlock = y_ / 16;

	//	Overwrite the existing tiles for each position (uses less resources than expected)
	for (int y = 0; y < vBlocks; ++y){
		for (int x = 0; x < hBlocks; ++x){
			/*
			int position = (((y+yBlock)*MAP_WIDTH) + (x+xBlock)*2); // Position of this tile in the tilemap
			
			backgrounds_[3].setTile( (x*2), (y*2), tilemap_[position]);
			backgrounds_[3].setTile( (x*2)+1, (y*2), tilemap_[position+1]);

			position += (MAP_WIDTH/2);
			backgrounds_[3].setTile( (x*2), (y*2) + 1, tilemap_[position]);
			backgrounds_[3].setTile( (x*2)+1, (y*2) + 1, tilemap_[position+1]);
			*/

			int position = (((y+yBlock)*MAP_WIDTH) + (x+xBlock)*2);
			Block b = blockMap_.blockAt(position);

			backgrounds_[3].setTile( (x*2), (y*2), b.loadedIndex_[3][0]);
			backgrounds_[3].setTile( (x*2)+1, (y*2), b.loadedIndex_[3][1]);

			backgrounds_[3].setTile( (x*2), (y*2) + 1, b.loadedIndex_[3][2]);
			backgrounds_[3].setTile( (x*2)+1, (y*2) + 1, b.loadedIndex_[3][3]);
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

	int xOffset = x_%16;
	int yOffset = y_%16;
	for (int i = 0; i < NUM_BACKGROUNDS; ++i){
		backgrounds_[i].moveTo(xOffset, yOffset);
	}
}
