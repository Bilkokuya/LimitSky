
#include "../lib/gba.h"
#include "../include/platform/gba/tilemap.h"
#include "../resources/tiles/tiles.h"

GBATilemap backgrounds[4] = {
	GBATilemap(0,0,0),
	GBATilemap(1,0,0),
	GBATilemap(2,0,0),
	GBATilemap(3,0,5)
};

int main()
{
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;

	SetPaletteBG(0,RGB(30,15,0));

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


	while(true);
}