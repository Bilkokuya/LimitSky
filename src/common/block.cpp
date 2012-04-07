#include "../../include/block.h"

Block::Block()
{
	for (int i = 0; i < 4; ++i)
		isLoaded_[i] = false;
}

Block::Block(const uint8_t* tiles[4])
{
	for (int i = 0; i < 4; ++i)
		tileData_[i] = tiles[i];
}