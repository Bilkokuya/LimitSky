#include "../../../include/base/tile.h"

Tile::Tile(const unsigned char* tiledata)
{
	tiledata_ = tiledata;
	charblockIndex_ = new unsigned char[5];

}
