#include "../../include/base/sprite.h"

//	Default Constructor for array use
Sprite::Sprite()
{
	x_ = 0;
	y_ = 0;
}

//	Constructor with default values for each parameter, see engine/sprite.h
Sprite::Sprite(int xPos, int yPos, int angle, float xScale, float yScale)
{
	x_ = xPos;
	y_ = yPos;
}

int Sprite::zPriority()
{
	return zPriority_;
}

//	Getter for the x co-ordinate
int	Sprite::x()
{ 
	return x_;
}

//	Getter for the y co-ordinate
int	Sprite::y()
{
	return y_;
}

//	Setter for the x co-ordinate
void Sprite::x(int xPosition) 
{ 
	x_ = xPosition;
}

//	Setter for the y co-ordinate
void Sprite::y(int yPosition) 
{ 
	y_ = yPosition;
}

//	Moves the sprite by dx and dy
void Sprite::move(int dx, int dy)
{
	x_ += dx;
	y_ += dy;
}

//	Moves the sprite to location x,y
void Sprite::moveTo(int x, int y)
{
	x_ = x;
	y_ = y;
}

