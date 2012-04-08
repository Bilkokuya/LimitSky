#ifndef LS_TILEDATA
#define LS_TILEDATA

#define PALETTE_LENGTH 6
const unsigned short bgpalette[PALETTE_LENGTH] = {
	0xF600, 0x0AA0, 0x05AA, 0x0277, 0x0880, 0x6F6F
};

const unsigned char tileSky [64] = {
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
};

const unsigned char tileGrassTL [64] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
};

const unsigned char tileGrassTR [64] = {
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
};

const unsigned char tileGrassBL [64] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	4, 4, 4, 4, 4, 4, 4, 4,
};

const unsigned char tileGrassBR [64] = {
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	1, 1, 1, 1, 1, 1, 1, 4,
	4, 4, 4, 4, 4, 4, 4, 4,
};


const unsigned char tileSoil [64] = {
	2, 2, 2, 2, 2, 2, 2, 2,
	2, 3, 3, 3, 3, 3, 3, 2,
	2, 3, 3, 3, 3, 3, 3, 2,
	2, 3, 3, 3, 3, 3, 3, 2,
	2, 3, 3, 3, 3, 3, 3, 2,
	2, 3, 3, 3, 3, 3, 3, 2,
	2, 3, 3, 3, 3, 3, 3, 2,
	2, 2, 2, 2, 2, 2, 2, 2,
};

const unsigned char tileDirt [64] = {
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
};

const unsigned char tileTallGrass [64] = {
	4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4,
};

#endif
