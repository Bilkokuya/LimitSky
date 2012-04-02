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

#include "gba\gba_sprite.h"
#include "unittest\mock_sprite.h"

};

#endif
