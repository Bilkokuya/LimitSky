//	Copyright 2012 Gordon D Mckendrick
//	LimitSky
//	Block
//		Represents a block the size shown in game for the world.
//		Is implemented as 2x2 tiles.
//		NB: Currently little use in this class, but it was originally more integral in old builds.
//			In future could have additional functionality added to fully abstract how the tiles work

#ifndef LS_BLOCK
#define LS_BLOCK

class Block
{
public:
	int tile_;	//	Tile number for the top left tile in this block

	Block (int tile);
};

#endif
