#ifndef LS_SPRITE
#define LS_SPRITE

///\brief A 2D sprite graphic that can be moved, rotated and scaled
///		Is non specific to any platform; making calls to the engine once a platform has been created
class Sprite
{
public:
	//	Default constructor for array use
	Sprite();
	//	Constructor for normal use
	Sprite(int xPos, int yPos, int angle = 0, float xScale = 1, float yScale = 1);

	//	Position Accesors
	int	x();
	int	y();
	void x(int xPosition);
	void y(int yPosition);
	void move(int dx, int dy);
	void moveTo(int x, int y);

	//	Priority Accessor
	int zPriority();

private:
	int x_;			///< The x co-ordinate of this sprite
	int y_;			///< The y co-ordinate of this sprite
	int zPriority_; ///< Z-Depth in the range 0 to 4, with 4 on top

#ifdef CC_GBA
public:
private:
	int size;
	int shape;
#endif

#ifdef CC_WIN32
public:
	//	Rotation Accessors
	int	rotation();
	void rotate(int dw);
	void rotation(int angle);

	//	Scale Accessors
	float scaleX();
	float scaleY();
	void scaleX(float scale);
	void scaleY(float scale);
	void scale(float dx, float dy);
	void scaleTo(float xScale, float yScale);

private:
	int width_;
	int height_;
	int rotation_;	///< Rotation in degrees from the positive x-axis
	float scaleX_;	///< Scale in the x-axis, where 1 is no scaling
	float scaleY_;	///< Scale in the y-axis, where 1 is no scaling

	///\brief Helper function that wraps the rotation around 360 degrees
	///			Ensures that the rotation functions do not bring values that will ever be out of range 0->360.
	void wrapRotation();
#endif

};

#endif
