//	Copyright 2012 Gordon D Mckendrick
//	Author: Gordon D Mckendrick
//
//	World

#include "world.h"
#include "engine/engine.h"

Block map[MAP_HEIGHT][MAP_WIDTH];

//	Document these when there is time
void harvest(int x, int y)
{
	Block* block = &map[x][y];
	block->setPlanted(false);
	block->cropTile = 0;
	SetTile(28,x,y,0);
}

void till(int x, int y)
{
	Block* block = &map[x][y];
	block->setTilled(true);
	block->groundTile = 2;
	SetTile(27,x,y,2);
}

void water(int x, int y)
{
	Block* block = &map[x][y];
	if (block->isTilled()){
		block->growth++;
		block->groundTile = 4;
		SetTile(27,x,y,4);
	}
}

void plant(int x, int y)
{
	Block* block = &map[x][y];
	if (block->isTilled()){
		block->setPlanted(true);
		block->cropTile = 5;
		SetTile(28,x,y,3);
	}
}

