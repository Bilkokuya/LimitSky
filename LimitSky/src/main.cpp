#include <stdint.h>
#include <stdlib.h>
#include "../lib/gba.h"
#include "../lib/font.h"
#include "tiles/tiles.h"
#include "player.h"
#include "util.h"

//	Tile block
struct Block
{
	int x, y;
	int groundTile;
	int cropTile;
	int growth;
	bool isWalkable;
	bool isFarmable;
	bool isTilled;
	bool isPlanted;

	Block(){
		x = 0;
		y = 0;
		groundTile = 0;
		isWalkable = false;
		isFarmable = false;
		isPlanted = false;
		isTilled = false;
		cropTile = 0;
		growth = 0;
	}

	Block(int x_, int y_, int groundTile_, bool isWalkable_, bool isFarmable_)
	{
		x = x_;
		y = y_;
		groundTile = groundTile_;
		isWalkable = isWalkable_;
		isFarmable = isFarmable_;
		isPlanted = false;
		isTilled = false;
		cropTile = 0;
		growth = 0;
	}

};


Block map[32][32];


int main()
{
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;
	
	REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 2;

	REG_BG1CNT = BG_CBB(0) | BG_SBB(29) | BG_8BPP | BG_REG_32x32;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;

	LoadTile8(0,0,blank_tile);
	LoadTile8(0,1,green_tile);
	LoadTile8(0,2,brown_tile);
	LoadTile8(0,3,blue_tile);
	LoadTile8(0,4,white_tile);

	LoadTile8(4,1,blue_tile);
	LoadTile8(4,2,white_tile);	
	
	//	Load BG Pallete
	for (int i=0; i < 256; i++) REG_PALETTE_BG[i] = palette_bg[i];

	//	Load Sprite Pallete
	for (int i=0; i < 256; i++) REG_PALETTE_OBJ[i] = palette_bg[i];

	for (int y = 0; y < 32; y++){
		for (int x = 0; x < 32; x++){
			map[x][y] = Block(x,y,1,true,true);
			SetTile(29,x,y,1);
		}
	}

	Player player = Player(50,50);

	while(true){
		player.onTick();

		WaitVSync();
		UpdateObjects();
	}

	return 0;
}


void harvest(int x, int y)
{
	Block* block = &map[x][y];
	block->isPlanted = false;
	block->cropTile = 0;
	SetTile(30,x,y,0);
}

void till(int x, int y)
{
	Block* block = &map[x][y];
	block->isTilled = true;
	block->groundTile = 2;
	SetTile(29,x,y,2);
}

void water(int x, int y)
{
	Block* block = &map[x][y];
	if (block->isTilled){
		block->growth++;
		block->groundTile = 4;
		SetTile(29,x,y,4);
	}
}

void plant(int x, int y)
{
	Block* block = &map[x][y];
	if (block->isTilled){
		block->isPlanted = true;
		block->cropTile = 5;
		SetTile(30,x,y,3);
	}
}

