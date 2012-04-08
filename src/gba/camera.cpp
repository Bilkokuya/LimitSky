#include "../../include/camera.h"

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

Camera::Camera(int width, int height, int xMin, int yMin, int xMax, int yMax, Sprite* s)
{
	setFocus(s);
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
	if (focus_){
		x_ = focus_->x() - width_/2;
		y_ = focus_->y() - height_/2;
	}

	//	Ensure it is within bounds
	if ((x_) < xMin_) x_ = xMin_;
	else if ((x_) > xMax_) x_ = xMax_;
	
	if ((y_) < yMin_) y_ = yMin_;
	else if ((y_) > yMax_) y_ = yMax_;
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
	return x_;
}

int Camera::y()
{
	return y_;
}