//	Copyright 2012 Gordon D Mckendrick
//
//	Limit Sky
//	Background
//		Abstraction of the GBA display backgrounds
//		Hides the details of screenblock and charblock once initialised.

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

	void setTile(int x, int y, int tile);						//	Sets the tile at the given x, y location
	void setBlock(int x, int y, int block);						//	Sets a block (2x2 tiles) at the given x,y location (top left)
	void loadTile(int tilenum, const unsigned char* tiledata);	//	Loads the given tile into this background

	//	Position accessors
	int x();
	int y();
	void x(int x);
	void y(int y);
	void move(int dx, int dy);
	void moveTo(int x, int y);

	// Background information accessors
	int number();
	int charblock();
	int screenblock();
	int zPriority();

private:
	int number_;			//	Which background of 4 this is (critically determines where in memory it looks)
	int x_, y_;				//	X and y offset positions
	int xOffset_, yOffset_;	//	Constant offset from the position. Making it simple to keep two backgrounds visually offset from each other, but at the same global position.
	int charblock_;			//	GBA Charblock this background takes tile data from
	int screenblock_;		//	GBA Screenblock this background renders to
	int zPriority_;			//	Depth priority of the background

	//	Common initialisation that all constructors use
	void init(int number, int xOffset, int yOffset, int zPriority, int charblock, int screenblock);
	
	void updateMemory();	//	Sets the GBA registers with the data for this background (used at initialisation)
	void updatePosition();	//	Updates the GBA offset registers for this background
};

//	Sets a block (2x2 tiles) onto the screen as tiles
inline void Background::setBlock(int x, int y, int block)
{
	setTile( x,   y,	blocks[block].tile_ );
	setTile( x+1, y,	blocks[block].tile_ + 1);
	setTile( x,   y+1,	blocks[block].tile_ + 16); // Tilemaps use a spritesheet layout, and so each row is 16 tiles long
	setTile( x+1, y+1,	blocks[block].tile_ + 16 + 1);
}

//	Sets a single tile onto the background - using Adam Sampson's implementation
inline void Background::setTile(int x, int y, int tile)
{
	SetTile(screenblock_, x,y, tile);
}

#endif
