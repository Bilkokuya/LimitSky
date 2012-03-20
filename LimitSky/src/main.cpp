//	Copyright 2012 Gordon D Mckendrick
//	Author: Gordon D Mckendrick
//
//	Main

#include <stdint.h>
#include <stdlib.h>
#include <string>
#include "../lib/gba.h"
#include "../lib/font.h"
#include "tiles/tiles.h"
#include "entity/player.h"
#include "util/util.h"
#include "world/world.h"
#include "tiles\memtest.h"

void initDisplay();		//	Initialises the display registers
void loadTiles();		//	Loads the tiles from arrays into the charblocks
void loadPalletes();	//	Loads the object and background palette


int main()
{
	//	Initialise the display, palettes and tiles
	initDisplay();
	loadTiles();
	loadPalletes();

	//	Set up the map of Blocks
	for (int y = 0; y < MAP_HEIGHT; y++){
		for (int x = 0; x < MAP_WIDTH; x++){
			map[x][y] = Block(x,y,1);
			SetTile(27,x,y,1);
		}
	}

	Player player = Player(50,50);
	printf("test");
	while(true){
		player.onTick();

		if (isKeyDown(KEY_LEFT)){
			loadHeap1();
		}else if (isKeyDown(KEY_RIGHT)){
			loadHeap2();
		}

		WaitVSync();
		UpdateObjects();
	}

	return 0;
}

/**
*	Function: initDisplay
*	Initialises the displays registers
*/
void initDisplay()
{
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
	
	//	Text UI layer
	REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;

	//	UI background layer
	REG_BG2CNT = BG_CBB(1) | BG_SBB(28) | BG_8BPP | BG_REG_32x32;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 3;

	//	Interactive/Crop layer
	REG_BG2CNT = BG_CBB(1) | BG_SBB(28) | BG_8BPP | BG_REG_32x32;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 3;

	//	Terrain layer
	REG_BG3CNT = BG_CBB(1) | BG_SBB(27) | BG_8BPP | BG_REG_32x32;
	REG_BG3HOFS = 0;
	REG_BG3VOFS = 0;
}


/**
*	Function: loadTiles
*	Loads the tiles from arrays into the charblocks
*/
void loadTiles()
{
	//	Load the tiles
	LoadTile8(1,0,blank_tile);
	LoadTile8(1,1,green_tile);
	LoadTile8(1,2,brown_tile);
	LoadTile8(1,3,blue_tile);
	LoadTile8(1,4,white_tile);

	LoadTile8(4,1,blue_tile);
	LoadTile8(4,2,white_tile);	

	//	Load in font tiles to CB1
	for(int i=0; i < 128; i++) LoadTile8(0,i,font_medium[i]);
}

/**
*	Function: loadPalettes
*	Loads the palette data for the objects and background
*/
void loadPalletes()
{
	//	Load BG Pallete
	for (int i=0; i < 256; i++) REG_PALETTE_BG[i] = palette_bg[i];

	//	Load Sprite Pallete
	for (int i=0; i < 256; i++) REG_PALETTE_OBJ[i] = palette_bg[i];
}
