#include "../../include/base/stage.h"
#include "../../include/base/displaylist.h"

#define MAX_SPRITES 128	//	Maximum number of sprites that can be on screen at once

//	Default Constructor
Stage::Stage()
{
	x_ = 0;
	y_ = 0;
	width_ = 240;
	height_ = 180;

	sprites_ = new Sprite*[ MAX_SPRITES ];
}

//	Default Destructor
Stage::~Stage()
{
	delete[] sprites_;
}

//	Returns the current sprites
Sprite** Stage::sprites()
{
	return sprites_;
}

//	Initialises the backgrounds and palettes
void Stage::init()
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