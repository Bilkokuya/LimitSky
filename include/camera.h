#ifndef LS_CAMERA
#define LS_CAMERA

#include "sprite.h"

class Camera
{
public:
	Camera();
	Camera(Sprite* s);

	void updatePosition();
	void setBounds(int xMin, int yMin, int xMax, int yMax);
	void setFocus(Sprite* s);

	int x();
	int y();

private:
	int x_, y_;
	int xMin_, yMin_, xMax_, yMax_;
	Sprite* focus_;
};

#endif