#ifndef LS_TILEMAPS
#define LS_TILEMAPS

#define MAP_WIDTH 32
#define MAP_HEIGHT 32
const unsigned char testTilemap[(MAP_WIDTH * MAP_HEIGHT)] = {
	 1,1,3,3,1,1,3,1,3,3,3,3,3,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,3,2,3,2,3,3,3,2,3,3,1,3,3,3,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,3,3,1,2,1,2,3,3,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,3,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,4,1,2,1,2,1,4,2,4,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,4,4,4,2,4,4,1,4,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,4,4,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,4,4,4,4,1,4,4,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,4,1,4,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,4,1,4,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,4,4,4,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
	 1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1,1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1 ,
	 1,1,2,1,2,1,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,1,2,1,2,1,2,1,2,1,2,1 ,
};

#endif