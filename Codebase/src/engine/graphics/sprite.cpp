#include "engine\sprite.h"

Sprite::Sprite(int xPos, int yPos, int angle, float xScale, float yScale)
{
	x_ = xPos;
	y_ = yPos;
	rotation_ = angle;
	scaleX_ = xScale;
	scaleY_ = yScale;
}


Sprite::~Sprite()
{
}


int	Sprite::x()
{ 
	return x_;
}

int	Sprite::y()
{
	return y_;
}

void Sprite::x(int xPosition) 
{ 
	x_ = xPosition;
}

void Sprite::y(int yPosition) 
{ 
	y_ = yPosition;
}


void Sprite::move(int dx, int dy)
{
	x_ += dx;
	y_ += dy;
}

void Sprite::moveTo(int x, int y)
{
	x_ = x;
	y_ = y;
}


int	Sprite::rotation()
{
	return rotation_;
}

void Sprite::rotate(int dw)
{
	rotation_ += dw;
	wrapRotation();
}

void Sprite::rotation(int angle)
{
	rotation_ = angle;
	wrapRotation();
}


float Sprite::scaleX()
{
	return scaleX_;
}

float Sprite::scaleY()
{
	return scaleY_;
}

void Sprite::scaleX(float scale)
{
	scaleX_ = scale;
}

void Sprite::scaleY(float scale)
{
	scaleY_ = scale;
}

void Sprite::scale(float dx, float dy)
{
	scaleX_ *= dx;
	scaleY_ *= dy;
}

void Sprite::scaleTo(float xScale, float yScale)
{
	scaleX_ = xScale;
	scaleY_ = yScale;
}

///\brief Ensure rotation is in the range 0->360 by wrapping around
void Sprite::wrapRotation()
{
	while (rotation_ > 360){
		rotation_ -= 360;
	}
	while (rotation_ < 0){
		rotation_ += 360;
	}
}
