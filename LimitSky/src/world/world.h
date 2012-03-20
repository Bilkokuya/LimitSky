//	Copyright 2012 Gordon D Mckendrick
//	Author: Gordon D Mckendrick
//
//	World

#ifndef LS_WORLD
#define LS_WORLD

//	Struct Block
struct Block
{
//	Offsets for the flags bytes, for each boolean in flags
#define WALKABLE_OFFSET	8
#define PLANTED_OFFSET	7
#define TILLED_OFFSET	6
#define FARMABLE_OFFSET	5

	unsigned short x, y;		//	x and y location in the world, in tiles, (Max distance 65000)
	unsigned char  groundTile;
	unsigned char  cropTile;
	unsigned char  growth;
	unsigned char  flags;	//	A simple representation of the boolean values - using less memory

	//	Constructor: default
	Block(){
		flags = 0;
		x = 0;
		y = 0;
		groundTile = 0;
		cropTile = 0;
		growth = 0;
	}

	//	Constructor: (int, int, int, bool = true, bool = true)
	Block(int x_, int y_, int groundTile_, bool isWalkable_ = true, bool isFarmable_ = true)
	{
		flags = 0;
		x = x_;
		y = y_;
		groundTile = groundTile_;
		setWalkable(isWalkable_);
		setFarmable(isFarmable_);
		cropTile = 0;
		growth = 0;
	}

	//	Accessors: Getters for flags
	//	Returns the current value from the flags byte
	bool isWalkable() { return (flags & (1 << WALKABLE_OFFSET)); }
	bool isFarmable() { return (flags & (1 << FARMABLE_OFFSET)); }
	bool isPlanted()  { return (flags & (1 << PLANTED_OFFSET)); }
	bool isTilled()   { return (flags & (1 << TILLED_OFFSET)); }

	//	Accessors: Setters for flags
	//	Sets byte in flags to either true or false
	//	Set if this block can be walked on
	void setWalkable(bool b){ 
		unsigned char mask = (1 << WALKABLE_OFFSET);
		mask = ~ (mask & 0xFFFF);
		flags = flags & mask;
		flags = flags | (b << WALKABLE_OFFSET);
	}

	//	Set whether the player can farm on this block or not
	void setFarmable(bool b){ 
		unsigned char mask = 1 << FARMABLE_OFFSET;
		mask = ~ (mask & 0xFFFF);
		flags = flags & mask;
		flags = flags | (b << FARMABLE_OFFSET);
	}
	//	Set whether this block has been planted on or not
	void setPlanted(bool b){ 
		unsigned char mask = 1 << PLANTED_OFFSET;
		mask = ~ (mask & 0xFFFF);
		flags = flags & mask;
		flags = flags | (b << PLANTED_OFFSET);
	}
	//	Set whether this block has been tilled or not
	void setTilled(bool b){
		unsigned char mask = 1 << TILLED_OFFSET;
		mask = ~ (mask & 0xFFFF);
		flags = flags & mask;
		flags = flags | (b << TILLED_OFFSET);
	}
};

//	The world map of all the terrain blocks
//	Each block is 8 Bytes
#define MAP_WIDTH 30
#define MAP_HEIGHT 20
extern Block map[MAP_HEIGHT][MAP_WIDTH];

void harvest(int x, int y);
void water(int x, int y);
void till(int x, int y);
void plant(int x, int y);

#endif
