#include "../../include/blockmap.h"

BlockMap::BlockMap()
{
}

BlockMap::BlockMap(const Block** blockMap)
{
	mapBlocks_ = blockMap;

}

Block BlockMap::blockAt(int position)
{
	return *mapBlocks_[position];
}