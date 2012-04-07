
#ifndef LS_BLOCK
#define LS_BLOCK

#include <stdint.h>

#define BLOCK_WIDTH 16	//	Width of a block in pixels
#define BLOCK_HEIGHT 16

class Block
{
public:
	const unsigned char* tileData_[4];
	unsigned char loadedIndex_[4][4];
	bool isLoaded_[4];

	Block();
	Block(const uint8_t* tiles[4]);

private:

};

#endif