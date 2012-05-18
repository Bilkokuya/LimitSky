//	Copyright 2012 Gordon D Mckendrick
//	LimitSky
//	Sprite
//		A simple sprite that draws onto the screen in OAM memory
//		Abstraction from the GBA implementation with the rendering handled external to this sprite

#ifndef LS_SPRITE
#define LS_SPRITE

class Sprite
{
public:
	//	Default constructor for array use
	Sprite();
	//	Constructor for normal use
	Sprite(int xPos, int yPos, int size, int shape, int tile, int zPriority = 2);

	//	Position Accesors
	int	x();
	int	y();
	void x(int xPosition);
	void y(int yPosition);
	void move(int dx, int dy);
	void moveTo(int x, int y);

	//	Priority Accessor
	int zPriority();

	//	Dimension Accessors
	int size();
	int shape();
	void size(int s);
	void shape(int s);

	//	Tile Data Accessor
	int tile();
	void tile(int t);

protected:
	int x_, y_;			//	x and y position, relative to the world
	int size_, shape_;	//	Determines the number of tiles wide and high it is
	int zPriority_;		//	Draw priority in the range 0->3, with 3 on top
	int tileNum_;		//	Tile for the top left of the sprite

};

#endif
