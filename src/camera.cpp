#include "../include/camera.h"

#include <math.h>
#include <cstdlib>

Camera::Camera()
{
	x_ = 0;
	y_ = 0;
	xMin_ = 0;
	yMin_ = 0;
	xMax_ = 240;
	yMax_ = 160;
	width_ = 240;
	height_ = 160;
	focus_ = 0;
}

Camera::Camera(int width, int height, int xMin, int yMin, int xMax, int yMax)
{
	setBounds(xMin, yMin, xMax, yMax);
	width_ = width;
	height_ = height;
	updatePosition();
}

void Camera::setFocus( Sprite* s)
{
	focus_ = s;
}

void Camera::updatePosition()
{
	//	Move to the new position
	//	Without a focus, it will stay still
	if (focus_){
		
		float dx = (focus_->x() - width_/2) - x_;
		float dy = (focus_->y() - height_/2) - y_;

		float magnitude = sqrt((float)((dx*dx)+(dy*dy)));
		float speed = 0;

		if (magnitude < 40) speed = 0;
		else if (magnitude < 60) speed = 0.5;
		else speed = 1.2;

		if ( ( (abs((int)dx) < 10) || (abs((int)dy) < 10) ) && (magnitude < 60) ) speed = 0;
	
		float ddx = dx/magnitude;
		float ddy = dy/magnitude;

		x_ += (speed * ddx);
		y_ += (speed * ddy);
	}

	//	Ensure it is within bounds
	if ( x_ < xMin_ ) x_ = xMin_;
	else if ( x_ > xMax_ ) x_ = xMax_;
	
	if ( y_ < yMin_ ) y_ = yMin_;
	else if ( y_ > yMax_ ) y_ = yMax_;
}

void Camera::setBounds(int xMin, int yMin, int xMax, int yMax)
{
	xMin_ = xMin;
	yMin_ = yMin;
	xMax_ = xMax;
	yMax_ = yMax;
}

int Camera::x()
{
	return ((int)x_);
}

int Camera::y()
{
	return ((int)y_);
}
