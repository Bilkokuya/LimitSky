#include "include\base\sprite.h"

#ifdef CC_UNITTEST
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
#endif
