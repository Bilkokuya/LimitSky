#ifndef LS_SPRITE
#define LS_SPRITE

///\brief A 2D sprite graphic that can be moved, rotated and scaled
///		Is non specific to any platform; making calls to the engine once a platform has been created
class Sprite 
{
public:

	Sprite(int xPos = 0, int yPos = 0, int angle = 0, float xScale = 1, float yScale = 1);
	~Sprite();

	int	x();
	int	y();

	void x(int xPosition);
	void y(int yPosition);

	void move(int dx, int dy);
	void moveTo(int x, int y);

	int	rotation();
	void rotate(int dw);
	void rotation(int angle);

	float scaleX();
	float scaleY();
	void scaleX(float);
	void scaleY(float);
	void scale(float dx, float dy);
	void scaleTo(float xScale, float yScale);

private:
	int x_, y_, rotation_;
	float scaleX_, scaleY_;

	void wrapRotation();
};

#endif
