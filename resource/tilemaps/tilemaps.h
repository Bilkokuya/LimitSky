#ifndef LS_TILEMAPS
#define LS_TILEMAPS

#include "../../include/block.h"
#include "../tiledata/tiledata.h"

#define MAP_WIDTH 32
#define MAP_HEIGHT 32
const unsigned char worldTilemap[(MAP_WIDTH * MAP_HEIGHT)] = {
	 1,4,4,4,3,4,4,1,2,2,2,2,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,2,2,3,3,3,2,2,2,2,2,1,2,2,2,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,3,1,3,2,2,1,3,3,3,2,3,1,1,1,3,1,3,3,3,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,3,1,2,2,3,1,3,1,3,1,1,1,3,1,3,1,1,1,1,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,3,1,2,1,3,1,3,1,3,1,1,1,3,1,3,3,1,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,3,1,1,1,3,1,3,2,2,3,1,3,2,2,3,1,2,1,2,1,2,1,2,1,2,1 ,
};

const uint8_t* dirtTiles[4] = { tileDirt, tileDirt, tileDirt, tileGrass};
const uint8_t* soilTiles[4] = { tileSoil, tileSoil, tileSoil, tileDirt};
const uint8_t* grassTiles[4] = { tileGrass, tileGrass, tileGrass, tileSoil};

Block grass = Block(grassTiles);
Block soil = Block(soilTiles);
Block dirt = Block(dirtTiles);

const Block* worldMap[(MAP_WIDTH * MAP_HEIGHT)] = {
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&soil,&soil,&soil,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&soil,&soil,&soil,&soil,&soil,&soil,&soil,&soil,&soil,&soil,&grass,&soil,&soil,&soil,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&dirt,&grass,&dirt,&soil,&soil,&soil,&grass,&soil,&grass,&soil,&soil,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&dirt,&dirt,&dirt,&dirt,&soil,&grass,&soil,&grass,&soil,&soil,&soil,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&dirt,&dirt,&dirt,&soil,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&soil,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&soil,&soil,&soil,&soil,&grass,&soil,&soil,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&soil,&soil,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
	 &grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass ,
	 &grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&soil,&grass,&grass,&grass,&grass,&soil,&soil,&grass,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass,&soil,&grass ,
};


#endif
