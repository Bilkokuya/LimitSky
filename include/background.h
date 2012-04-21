
#ifndef LS_BACKGROUND
#define LS_BACKGROUND

#include "../resource/blocks.h"
#include "../lib/gba.h"

//	Represents the background class
//	NB: There are inline functions at the bottom of this file
class Background
{
public:
	Background();
	Background(int number, int xOffset = 0, int yOffset = 0, int zPriority = 0);
	Background(int number, int xOffset, int yOffset, int zPriority, int charblock, int screenblock);

	void setTile(int x, int y, int tile);
	void setBlock(int x, int y, int block);
	void loadTile(int tilenum, const unsigned char* tiledata);

	int x();
	int y();
	void x(int x);
	void y(int y);
	void move(int dx, int dy);
	void moveTo(int x, int y);

	int number();
	int charblock();
	int screenblock();
	int zPriority();

private:
	int number_;
	int x_;
	int y_;
	int xOffset_, yOffset_;
	int charblock_;
	int screenblock_;
	int zPriority_;

	void init(int number, int xOffset, int yOffset, int zPriority, int charblock, int screenblock);
	void updateMemory();
	void updatePosition();
};

//	Sets a block (2x2 tiles) onto the screen as tiles
inline void Background::setBlock(int x, int y, int block)
{
	setTile( x,   y,	blocks[block].tile_ );
	setTile( x+1, y,	blocks[block].tile_ + 1);
	setTile( x,   y+1,	blocks[block].tile_ + 16);
	setTile( x+1, y+1,	blocks[block].tile_ + 17);
}

//	Sets a single tile onto the background - using Adam Sampson's implementation
inline void Background::setTile(int x, int y, int tile)
{
	SetTile(screenblock_, x,y, tile);
}

#endif
