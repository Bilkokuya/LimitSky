#include "engine\sprite.h"
#include "engine\engine.h"

//	Default Constructor for array use
Sprite::Sprite()
{
	x_ = 0;
	y_ = 0;
	rotation_ = 0;
	scaleX_ = 1;
	scaleY_ = 1;
}

//	Constructor with default values for each parameter, see engine/sprite.h
Sprite::Sprite(int xPos, int yPos, int angle, float xScale, float yScale)
{
	x_ = xPos;
	y_ = yPos;
	rotation_ = angle;
	scaleX_ = xScale;
	scaleY_ = yScale;

	displayList.addSprite(this);
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

//	Getter for the rotation in degrees
int	Sprite::rotation()
{
	return rotation_;
}

//	Rotates by dw degrees anticlockwise
//	Wraps into the range 0->360
void Sprite::rotate(int dw)
{
	rotation_ += dw;
	wrapRotation();
}

//	Sets the rotation as angle degrees anticlockwise
//	Wraps the rotation into the range 0->360
void Sprite::rotation(int angle)
{
	rotation_ = angle;
	wrapRotation();
}

//	Gets the current x-axis scale 
float Sprite::scaleX()
{
	return scaleX_;
}

//	Gets the current y-axis scale
float Sprite::scaleY()
{
	return scaleY_;
}

//	Sets the x-axis scale
void Sprite::scaleX(float scale)
{
	scaleX_ = scale;
}

//	Sets the y-axis scale
void Sprite::scaleY(float scale)
{
	scaleY_ = scale;
}

//	Scales by a factor of dx and dy
void Sprite::scale(float dx, float dy)
{
	scaleX_ *= dx;
	scaleY_ *= dy;
}

//	Scales to the values xScale and yScale
void Sprite::scaleTo(float xScale, float yScale)
{
	scaleX_ = xScale;
	scaleY_ = yScale;
}

//	Gets the bitmap that this sprite uses
Bitmap Sprite::bitmap()
{
	return bitmap_;
}

//	Set the bitmap this sprite should use
void Sprite::bitmap(Bitmap bmp)
{
	bitmap_ = bmp;
}


//	Ensures rotation is wrapped into the range 0->360 degrees
void Sprite::wrapRotation()
{
	while (rotation_ > 360){
		rotation_ -= 360;
	}
	while (rotation_ < 0){
		rotation_ += 360;
	}
}