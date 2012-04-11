#include "../include/display.h"
#include "../lib/gba.h"
#include "../lib/font.h"
#include "../resource/tiles/palette.h"
#include "../resource/tiles/terraintiles.h"
#include "../include/background.h"
#include "../resource/maps/map.h"

#define NUM_BGS 4			//	Number of backgrounds
#define NUM_SPRITES 128		// Maximum number of OAM sprites

#define X_WRAPAROUND 512	//	Value x becomes when wrapping below 0
#define Y_WRAPAROUND 256	//	Value y becomes when wrapping below 0

Display::Display(int x, int y, int width, int height, Camera* camera)
{
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
	camera_ = camera;

	lBuff_ = 31;
	rBuff_ = 30;
	right_ = 8;
	left_ = -8;

	initRegisters();
	initPalettes();
	initTiles();
}

void Display::initRegisters()
{
	//	Initialises the main GBA display registers for drawing tiles
	//		(Individual background registers are initialised by the background objects themselves)
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
	
	//	Initialise the Background registers
	bgs_[0] = Background(0,0,0,2);
	bgs_[1] = Background(1,0,0,2);
	bgs_[2] = Background(2,0,0,0);
	bgs_[3] = Background(3,0,0,0);
}


void Display::initPalettes()
{
	//	Initialise the palette
	for (int i = 0; i < palettePalLen; ++i){
		SetPaletteBG(i, palettePal[i]);
	}
}

//	Loads up all the tiles into memory
void Display::initTiles()
{
	for (int i = 0; i < terraintilesTilesLen; i+=64){
		bgs_[4].loadTile(i, &terraintilesTiles[i]);
	}
}

void Display::render()
{	
	moveTo(camera_->x(), camera_->y());

	renderSprites();
	renderTiles();
}

void Display::renderTiles()
{
	//	Move Buffers when necessary
		if (x_ <= left_){
			left_ -= 8;
			right_ -= 8;
			lBuff_--;
			rBuff_--;

		}else if (x_ >= right_){
			left_ += 8;
			right_+= 8;
			lBuff_++;
			rBuff_++;
		}

		// Keep buffers in range 0->31
		wrapInRange(0,31,lBuff_);
		wrapInRange(0,31,rBuff_);

		//	Draw the buffers
		for (int i = 0; i < 32; ++i){
			bgs_[3].setTile(lBuff_, i, map[(i*MAPWIDTH) + (x_/8) ]);
			bgs_[3].setTile(rBuff_, i, map[(i*MAPWIDTH) + (x_/8) +30]);
		}
}

void Display::wrapInRange(int min, int max, int& i)
{
	if (i > max) i = min;
	else if (i < min) i = max;
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
		if(nextSprite > NUM_SPRITES) break;
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

	for (int i = 2; i < NUM_BGS; ++i){
		bgs_[i].moveTo(x_, y_);
	}
}
