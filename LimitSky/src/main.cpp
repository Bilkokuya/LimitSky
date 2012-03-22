//	Copyright 2012 Gordon D Mckendrick
//	Author: Gordon D Mckendrick
//
//	Main

#include <stdint.h>
#include <stdlib.h>
#include <string>
#include "../lib/gba.h"
#include "../lib/font.h"
#include "../resources/tiles/tiles.h"
#include "entity/player.h"
#include "util/util.h"
#include "world/world.h"

void initDisplay();		//	Initialises the display registers
void loadTiles();		//	Loads the tiles from arrays into the charblocks
void loadPalletes();	//	Loads the object and background palette

///\brief Represents an entire background register for the display
///		with simple functions for easy access to contained information
///
///\warning Name may suggest this is REGISTER, it is simply a struct.
///		It replaces direct register access, and so maintains the naming conventions previously used there.
struct REG_BG
{
#define BASE_BGCNT REGISTER(uint16_t, 0x4000008)	//	Base register of the bg control bits
#define BASE_BGHOFS REGISTER(uint16_t, 0x400001C)	//	Base register of the bg horizontal offset
#define BASE_BGVOFS REGISTER(uint16_t, 0x4000012)	//	Base register of the bg vertical offset

	///\brief Initialises this BG, using standard charblock and screenblock numbering
	///\param bgNumber A number between 0 and 3, for which background layer this is
	///\param xOff The starting horizontal offset to the left
	///\param yOff The starting vertical offset, downwards
	///\warning bgNumbers out of the 0->3 range are placed at the ends of this range to avoid running off memory
	REG_BG(int bgNumber, int xOff=0, int yOff=0)
	{
		init(bgNumber,xOff,yOff,bgNumber,30-bgNumber);
	}

	///\brief Initialises this BG, with specified charblock and screenblock numbering
	///\param bgNumber A number between 0 and 3, for which background layer this is
	///\param xOff The starting horizontal offset to the left
	///\param yOff The starting vertical offset, downwards
	///\param charblock the charblock to be used for this background
	///\param screenblock the screenblock to be used for this background
	///\warning bgNumbers and charblocks are forced into the range 0->3, use charblock 0 first and ascend.
	///\warning screenblocks are forced into the range 30->0; use screenblock 30 first and then descend.
	REG_BG(int bgNumber, int xOff, int yOff, int charblock, int screenblock)
	{
		init(bgNumber,xOff,yOff,charblock,screenblock);
	}

	///\brief Sets the offset of this BG in absolute terms
	///\param xOff the x offset of this BG, to the left
	///\param yOff the y offset of this BG, downwards
	void setOffset(int xOff, int yOff)
	{
		x = xOff;
		y = yOff;

		updateOffset();
	}

	///\brief Offsets this BG, relative to where it is
	///\param dx the offset to be added to the left
	///\param dy the offset to be added downwards
	void offset(int dx, int dy)
	{
		x += dx;
		y += dy;

		updateOffset();
	}

	///\brief Getter for the current x value
	int X() { return x; }

	///\brief Getter for the current y value
	int Y() { return y; }

private:
	volatile uint16_t* control;	///< Pointer to the control Register that specifies the charblock used etc.
	volatile uint16_t* hOffset;	///< Pointer to the Horizontal Offset register for this background
	volatile uint16_t* vOffset;	///< Pointer to the Vertical Offset register for this background
	int x,y;					///< Current x and y offsets

	///\brief Initialises the registers
	///	Params are all from constructor, check there for definition
	void init(int bgNumber, int xOff, int yOff, int charblock, int screenblock)
	{
		//	Ensure values are within bounds
		if (bgNumber > 3) bgNumber = 3;
		if (bgNumber < 0) bgNumber = 0;
		if (charblock < 0) charblock = 0;
		if (charblock > 3) charblock = 3;
		if (screenblock < 0) screenblock = 0;
		if (screenblock > 30) screenblock = 30;

		x = xOff;
		y = yOff;

		//	Each new background register is offset by 0x1 from the previous one (the same as offsetting by the bgNumber), while the offset registers have double spacing
		control = &BASE_BGCNT + bgNumber;
		hOffset = &BASE_BGHOFS + (2*bgNumber);
		vOffset = &BASE_BGVOFS + (2*bgNumber);

		//	Initialise the controls and starting offset
		*control = BG_CBB(charblock) | BG_SBB(screenblock) | BG_8BPP | BG_REG_32x32;
		setOffset(xOff,yOff);
	}

	///\brief Updates the offset registers to the current x and y values
	///			To be called straight after any changes to x or y are made.
	void updateOffset()
	{
		*hOffset = x;
		*vOffset = y;
	}
};


REG_BG bgs[4] = {	REG_BG(0,0,0),
					REG_BG(1,0,0),
					REG_BG(2,0,3),
					REG_BG(3,0,0)	};

///\brief Main initialisation and control functionality
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
			if (((x+y)%2)==0) SetTile(27,x,y,4);
		}
	}

	Player player = Player(50,50);
	while(true){
		player.onTick();

		for (int i = 0; i < 4; i++) bgs[i].offset(1,0);

		WaitVSync();
		UpdateObjects();
	}

	return 0;
}

///\brief Initialises the display registers
void initDisplay()
{
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
}

/** Loads the tiles from arrays into the charblocks
*/
void loadTiles()
{
	//	Load the tiles
	LoadTile8(1,0,blank_tile);
	LoadTile8(1,1,green_tile);
	LoadTile8(1,2,brown_tile);
	LoadTile8(1,3,blue_tile);
	LoadTile8(1,4,white_tile);

	LoadTile8(3,0,blank_tile);
	LoadTile8(3,1,green_tile);
	LoadTile8(3,2,brown_tile);
	LoadTile8(3,3,blue_tile);
	LoadTile8(3,4,white_tile);

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
