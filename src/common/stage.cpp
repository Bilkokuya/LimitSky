#include "../../include/base/stage.h"
#include "../../include/base/displaylist.h"
#include "../../lib/gba/gba.h"

#define MAX_SPRITES 128	//	Maximum number of sprites that can be on screen at once
#define MAX_BACKGROUNDS 4

//	Easy access to change the initial background offsets - without diving into code.
const int BG_OFFSETS [MAX_BACKGROUNDS][2] = { 
	{0,0},
	{5,5},
	{8,8},
	{10,10}
};

//	Default Constructor
Stage::Stage()
{
	//	Initialise the display registers
	initDisplay();

	initSprites();

	initBackgrounds();

	x_ = 0;
	y_ = 0;
	width_ = 240;
	height_ = 180;
}

//	Default Destructor
Stage::~Stage()
{
	//	Ensure safe deletion of all objects in the stage
	for (int i = 0; i < backgroundsIndex_; ++i)
		delete backgrounds_[i];

	for (int i = 0; i < spritesIndex_; ++i)
		delete sprites_[i];

	delete[] backgrounds_;
	delete[] sprites_;
}

//	Returns the current sprites
Sprite** Stage::sprites()
{
	return sprites_;
}


//	Initialises the backgrounds and palettes
void Stage::initDisplay()
{
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
}

//	Initialises the backgrounds and palettes
void Stage::initBackgrounds()
{
	backgrounds_ = new Background*[ MAX_BACKGROUNDS ];
	backgroundsIndex_ = 0;

	for (int i=0; i < MAX_BACKGROUNDS; ++i){
		addBackground(new Background(i,BG_OFFSETS[i][0],BG_OFFSETS[i][1]));
	}
}

//	Initialises the backgrounds and palettes
void Stage::initSprites()
{
	sprites_ = new Sprite*[ MAX_SPRITES ];
	spritesIndex_ = 0;
}

//	Initialises the backgrounds and palettes
void Stage::initPalettes()
{
}


//	Updates the spritelists and tile data
void Stage::update()
{
}

//	Draws the sprite data into the OAM and tiles into the backgrounds
void Stage::draw()
{
}

void Stage::addBackground(Background* background)
{
	if (backgroundsIndex_ < MAX_BACKGROUNDS){
		backgroundsIndex_++;
		backgrounds_[background->number()] = background;
	}
}


// gets the current x position
int Stage::x()
{
	return x_;
}

// gets the current y position
int Stage::y()
{ 
	return y_;
}

// sets the new x position
void Stage::x(int xPos)
{ 
	x_ = xPos;
}

// sets the new y position
void Stage::y(int yPos) 
{ 
	y_ = yPos;
}

// moves by the specified amount
void Stage::move(int dx, int dy)
{ 
	x_ += dx;
	y_ += dy;
}

// moves to the specified location
void Stage::moveTo(int x, int y) 
{ 
	x_ = x;
	y_ = y;
}


// gets the current width
int Stage::width() 
{
	return width_;
}

// gets the current height
int Stage::height() 
{
	return height_;
}

// sets the new width
void Stage::width(int w) 
{ 
	width_ = w;
}

// sets the new height
void Stage::height(int h)
{ 
	height_ = h;
}

// sets the stage dimensions
void Stage::setDimensions(int width, int height)
{ 
	width_ = width;
	height_ = height;
}