//	Common functionality for the tile classes

#ifndef LS_TILE
#define LS_TILE

class Tile
{
public:
	Tile();
private:

#ifdef CC_GBA
public:
	Tile(const unsigned char* tiledata);

	const unsigned char* tiledata_;
	int charblockIndex_[5]; // Index that this tile has been loaded into for each charblock it could be in (charblock is the index).
private:
#endif

};

#endif
