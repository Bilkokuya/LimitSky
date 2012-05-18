#include "../include/display.h"
#include "../lib/gba.h"
#include "../lib/font.h"
#include "../resource/tiles/palettes.h"
#include "../resource/tiles/spritepalette.h"
#include "../resource/tiles/terraintiles.h"
#include "../resource/tiles/spritetiles.h"
#include "../include/background.h"
#include "../resource/maps/blockmap.h"
#include "../resource/blocks.h"

#define NUM_BGS 4			//	Number of backgrounds
#define NUM_SPRITES 128		// Maximum number of OAM sprites

#define X_WRAPAROUND 512	//	Value x becomes when wrapping below 0
#define Y_WRAPAROUND 256	//	Value y becomes when wrapping below 0

Display::Display(int x, int y, int width, int height)
{
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;

	initRegisters();
	initPalettes();
	initTiles();
}

int Display::red(uint16_t colour)
{
	return ( (colour & 0x001F) );
}

int Display::green(uint16_t colour)
{
	return ( (colour & 0x003E0)>>5 );
}

int Display::blue(uint16_t colour)
{
	return ( (colour & 0x7C00)>>10 );
}

void Display::transformPalette(int* transform)
{
	paletteTransform( transform, palettesPal, REG_PALETTE_BG);
	paletteTransform( transform, spritepalettePal, REG_PALETTE_OBJ);
};

void Display::paletteTransform(int* transform, const unsigned short* originalPallete, volatile uint16_t* paletteReg)
{
	for (int i = 0; i < 256; ++i){
		int c[3];
		c[0] = red(originalPallete[i]) - transform[0];
		c[1] = green(originalPallete[i]) - transform[1];
		c[2] = blue(originalPallete[i]) - transform[2];

		//	Ensure they are within the 0->31 range for colour components
		for (int j = 0; j < 3; ++j){
			if (c[j] < 0) c[j] = 0;
			if (c[j] > 31) c[j] = 31;
		}

		paletteReg[i] = RGB(c[0],c[1],c[2]);
	}
}

void Display::initRegisters()
{
	//	Initialises the main GBA display registers for drawing tiles
	//		(Individual background registers are initialised by the background objects themselves)
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
	
	//	Initialise the Background registers
	bgs_[0] = Background(0,0,0,0);
	bgs_[1] = Background(1,0,0,0);
	bgs_[2] = Background(2,0,5,2);
	bgs_[3] = Background(3,0,0,3);
}


void Display::initPalettes()
{
	for (int i = 0; i < palettesPalLen; ++i){
		SetPaletteBG(i, palettesPal[i]);
		SetPaletteObj(i, spritepalettePal[i]);
	}
}

//	Loads up all the tiles into memory
void Display::initTiles()
{
	//	Load map tiles
	for (int n = 0; n < 2; ++n){
		for (int i = 0; i < (terraintilesTilesLen/64); ++i){
			bgs_[3-n].loadTile(i, &terraintilesTiles[i*64]);
		}
	}

	//	Load font to UI (Background 0)
	for (int i = 0; i < 128; ++i){
		bgs_[0].loadTile(i, font_medium[i]);
	}

	//	Load the sprite tiles into CB 4
	for (int i = 0; i < (spritetilesTilesLen/64); ++i){
		LoadTile8(4, i, &spritetilesTiles[i*64]);
	}
}

int frame = 0;

void Display::update()
{
	moveTo(camera_->x(), camera_->y());
}

void Display::render()
{	
	renderSprites();

	renderTerrain();
	

	if ((frame%8)==0)
		renderUI();

	frame++;
}

void Display::renderTerrain()
{
	int yStart = (y_/16) * MAPWIDTH;
	int xStart = (x_/16);
	int start = xStart + yStart;

	int xP = 0;
	int yP = 0;
	int yy = 0;
	for (int y = 0; y < 16; ++y){
		for (int x = 0; x < 16; ++x){
			int position = start + yy + x;
			bgs_[3].setBlock(xP, yP, world_->maps_[0][position]);
			bgs_[2].setBlock(xP, yP, world_->maps_[1][position]);
			xP += 2;
		}
		xP = 0;
		yP += 2;
		yy += MAPWIDTH;
	}
}

void Display::renderCrops()
{
	for (int y = 0; y < 12; ++y){
		for (int x = 0; x < 16; ++x){
			bgs_[2].setBlock(x*2, y*2, world_->maps_[1][(((y_/16) + y)*MAPWIDTH) + (x_/16) + x]);
		}
	}
}

void Display::renderUI()
{
	//Render ui changes made
		for (int i = 0; i < ui_->numberOfChanges_[1]; ++i){
			int x = ui_->changes_[1][i][0];
			int y = ui_->changes_[1][i][1];
			int tile = ui_->changes_[1][i][2];

			bgs_[0].setTile(x,y,tile);
		}
		ui_->numberOfChanges_[1] = 0;
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
		//	Set the sprite if it is currently on the screen
		if ( (((sprite->x()) + 8) < x_) || (sprite->x() > (x_ + width_)) ) continue;
		if ( (((sprite->y()) + 8) < y_) || (sprite->y() > (y_ + height_)) ) continue;

		int x = sprite->x() - x_;	//	x position to draw to (range 0-> X_WRAPAROUND)
		int y = sprite->y() - y_;	//	y position to draw to (range 0-> Y_WRAPAROUND)

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


void Display::registerCamera(Camera* camera)
{
	camera_ = camera;
}

void Display::registerUI(UI* ui)
{
	ui_ = ui;
	for (int i = 0; i < 20; ++i){
		for (int j = 0; j < 30; ++j){
			bgs_[1].setTile(j,i, ui_->background_[i*30 + j]);
		}
	}
}

void Display::registerWorld(World* world)
{
	world_ = world;
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
