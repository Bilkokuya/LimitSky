#define TRUE 1
#define FALSE 0

#include <cstdlib>

#include "../../include/display.h"
#include "../../lib/gba/gba.h"
#include "../../include/sprite.h"
#include "../../resource/tiledata/tiledata.h"


const unsigned char tile[64] = {
	5,5,5,5,5,5,5,5,
	5,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,5,
	5,5,5,5,5,5,5,5
};

int main()
{
	Display display = Display(0,0,SCREEN_WIDTH, SCREEN_HEIGHT);

	for (int i = 0; i < 256; i++)
		LoadTile8(4,i,tile);

	SetPaletteObj(5,0xF0F0);

	Sprite* s = new Sprite(5,10);
	s->tile(2);
	display.registerSprite(s);

	for (int i = 0; i < 5; ++i){
		Sprite* sprite = new Sprite(i, rand()%SCREEN_HEIGHT);
		sprite->tile(2);
		display.registerSprite(sprite);
	}

	ClearObjects();

	int lasthit = 0;

	while(true)
	{
		//	Movement of the display on a key press
		if (lasthit != REG_P1){
			//Logic Updates
			if ((REG_P1 & KEY_LEFT) == 0)		display.move(-1,0);
			else if ((REG_P1 & KEY_RIGHT)==0)	display.move(1,0);
			else if ((REG_P1 & KEY_UP) == 0)	display.move(0,-1);
			else if ((REG_P1 & KEY_DOWN) == 0)	display.move(0,1);
		}
		lasthit = 0; // Set to REG_P1 to stop holding of keys.

		//	Keep the display in bounds of the tilemap it draws from
		if (display.x() < 0) display.x(0);
		if (display.x() > ((64*8) - 8*30)) display.x(8*64 - 8*30);

		if (display.y() < 0) display.y(0);
		if (display.y() > ((32*8) - 8*22)) display.y(8*32 - 8*22);

		
		//Rendering
		display.render();
		WaitVSync();
		UpdateObjects();
	}

	return 0;
}
