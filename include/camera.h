//	Copyright 2012 Gordon D Mckendrick
//	LimitSky
//	Camera
//		A camera that follows any given sprite and allows displays to render specific parts of the screen
//		Designed to be set to a player (setFocus()), but can use anything that extends Sprite
//		Could be easily used in cutscenes or other interesting things.

#ifndef LS_CAMERA
#define LS_CAMERA

#include "sprite.h"

class Camera
{
public:
	Camera();
	Camera(int width, int height, int xMin, int yMin, int xMax, int yMax);

	//	Moves the camera to point with the centre above the focus sprite
	void updatePosition();
	
	//	Set new min and max boundaries for the camera movement (such as map bounds)
	void setBounds(int xMin, int yMin, int xMax, int yMax);

	//	Set the sprite that the camera will follow
	void setFocus(Sprite* s);

	//	Position accessors
	int x();
	int y();

private:
	float x_, y_;					//	The GBA is slow with floats, but the increased movement accuracy is visually noticable
	int width_, height_;			// Width and Height for checking bounds
	int xMin_, yMin_, xMax_, yMax_; // Current boundaries for camera position
	Sprite* focus_;					// The sprite that's currently being looked at.
};

#endif
