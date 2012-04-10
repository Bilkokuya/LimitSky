#include "../lib/gba.h"
#include "../resource/maps/map.h"
#include "../resource/tiles/terraintiles.h"
#include "../resource/tiles/palettes.h"
#include "../include/display.h"
#include "../include/sprite.h"

void wrapInRange(int min, int max, int& i);

int main()
{
	Sprite s = Sprite(0,0,0,0,1,0);
	Camera camera = Camera(SCREEN_WIDTH, SCREEN_HEIGHT, 0,0, MAPWIDTH*8, 32*8, &s);
	Display display = Display(0,0,SCREEN_WIDTH,SCREEN_HEIGHT, &camera);

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
			s.move(1,0);

		}else if ((REG_P1 & KEY_LEFT) == 0){
			xOff--;
			s.move(-1,0);
		} 
		if ((REG_P1 & KEY_UP) == 0){
			yOff--;
			s.move(0,-1);

		}else if ((REG_P1 & KEY_DOWN) == 0){
			yOff++;
			s.move(0,1);
		}

		camera.updatePosition();

		display.render();
		WaitVSync();
		UpdateObjects();
		//REG_BG3HOFS = xOff;
		//REG_BG3VOFS = yOff;
	}
}

