#ifndef LS_SPRITE
#define LS_SPRITE

class Sprite
{
public:
	//	Default constructor for array use
	Sprite();
	//	Constructor for normal use
	Sprite(int xPos, int yPos);

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
	int x_, y_;			//	x and y position, relative to the world
	int size_, shape_;	//	Determines the number of tiles wide and high it is
	int zPriority_;		//	Draw priority in the range 0->3, with 3 on top
	int tileNum_;		//	Tile for the top left of the sprite

};

#endif
