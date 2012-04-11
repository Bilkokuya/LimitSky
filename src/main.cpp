#include "../lib/gba.h"
#include "../resource/maps/map.h"
#include "../resource/tiles/terraintiles.h"
#include "../resource/tiles/palettes.h"
#include "../include/display.h"
#include "../include/sprite.h"

bool isDown(int key);

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

	while(true)
	{
		//	Controls
		if (isDown(KEY_RIGHT)){
			s.move(1,0);

		}else if (isDown(KEY_LEFT)){
			s.move(-1,0);
		} 
		if (isDown(KEY_UP)){
			s.move(0,-1);

		}else if (isDown(KEY_DOWN)){
			s.move(0,1);
		}

		camera.updatePosition();
		display.render();

		WaitVSync();
		UpdateObjects();
	}
}

bool isDown(int key)
{
	return ((REG_P1 & key) == 0);
}
