
#ifndef LS_BLOCKMAP
#define LS_BLOCKMAP

#include "block.h"

class BlockMap
{
public:
	BlockMap();
	BlockMap(const Block** blockMap);

	Block blockAt(int position);

private:
	const Block** mapBlocks_;
	Block** changes_;

};

#endif

