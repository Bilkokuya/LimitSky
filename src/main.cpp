#include "../lib/gba.h"
#include "../resource/maps/map.h"
#include "../resource/tiles/terraintiles.h"
#include "../resource/tiles/palettes.h"
#include "../include/display.h"
#include "../include/sprite.h"

void wrapInRange(int min, int max, int& i);

int main()
{

	Display display = Display(0,0,SCREEN_WIDTH,SCREEN_HEIGHT, new Camera());

	Sprite s = Sprite(20,5,0,0,1,1);
	display.registerSprite(&s);

	LoadTile8(4,1,&terraintilesTiles[256]);

	for (int i = 0; i < terraintilesTilesLen; i += 64){
		LoadTile8(3, i/64, &terraintilesTiles[i]);
	}

	for (int i = 0; i < palettesPalLen; ++i){
		SetPaletteBG(i, palettesPal[i]);
		SetPaletteObj(i, palettesPal[i]);
	}

	for (int i = 0; i < 32; ++i){
		for (int j = 0; j < 32; ++j){
			SetTile(27,j,i, map[i*MAPWIDTH + j]);
		}
	}

	int xOff = 0;
	int yOff = 0;

	int lBuff = 31;
	int rBuff = 30;

	int right = 8;
	int left = -8;

	int xTiles = 0;

	while(true)
	{
		//	Controls
		if ((REG_P1 & KEY_RIGHT) == 0){
			xOff++;
		}else if ((REG_P1 & KEY_LEFT) == 0){
			xOff--;
		} 
		if ((REG_P1 & KEY_UP) == 0){
			yOff--;
		}else if ((REG_P1 & KEY_DOWN) == 0){
			yOff++;
		}

		//	Keep in map bounds
		if (xOff > (8*MAPWIDTH - 30*8)) xOff = (8*MAPWIDTH - 30*8);
		if (xOff < 0) xOff = 0;
		if (yOff > (8*32 - (20*8))) yOff = 8*32 - (20*8);
		if (yOff < 0) yOff = 0;

		//	Move Buffers when necessary
		if (xOff <= left){
			left -= 8;
			right -= 8;
			lBuff--;
			rBuff--;
			xTiles--;

		}else if (xOff >= right){
			left += 8;
			right += 8;
			lBuff++;
			rBuff++;
			xTiles++;
		}

		// Keep buffers in range 0->31
		wrapInRange(0,31,lBuff);
		wrapInRange(0,31,rBuff);

		//	Draw the buffers
		for (int i = 0; i < 32; ++i){
			SetTile(27, lBuff, i, map[((i)*MAPWIDTH) + xOff/8 ]);
			SetTile(27, rBuff, i, map[((i)*MAPWIDTH) + xOff/8 + 30 ]);
		}

		display.render();
		WaitVSync();
		REG_BG3HOFS = xOff;
		REG_BG3VOFS = yOff;
	}
}

void wrapInRange(int min, int max, int& i)
{
	if (i > max) i = min;
	else if (i < min) i = max;
}