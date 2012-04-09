#define TRUE 1
#define FALSE 0

#include <cstdlib>

#include "../../include/display.h"
#include "../../lib/gba/gba.h"
#include "../../include/sprite.h"
#include "../../resource/tiledata/tiledata.h"
#include "../../include/world.h"
#include "../../include/ui.h"


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
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
	REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;
	REG_BG1CNT = BG_CBB(1) | BG_SBB(29) | BG_8BPP | BG_REG_32x32;
	REG_BG2CNT = BG_CBB(2) | BG_SBB(28) | BG_8BPP | BG_REG_32x32;
	REG_BG3CNT = BG_CBB(3) | BG_SBB(27) | BG_8BPP | BG_REG_32x32;

	for (int i = 0; i < PALETTE_LENGTH; ++i){
		SetPaletteBG(i, bgpalette[i]);
		SetPaletteObj(i, bgpalette[i]);
	}

	while(true){


		WaitVSync();
		UpdateObjects();
	}

}
/*
int main()
{
	World world = World();
	UI ui = UI();
	Camera camera = Camera();
	Display display = Display(0,0,SCREEN_WIDTH, SCREEN_HEIGHT, &world, &ui, &camera);

	for (int i = 0; i < 256; i++)
		LoadTile8(4,i,tile);

	SetPaletteObj(5,0xF0F0);

	Sprite* s = new Sprite(5,10);
	s->tile(2);

	display.registerSprite(s);

	camera = Camera(240,160,0,0,500,300,s);

	for (int i = 0; i < 5; ++i){
		Sprite* sprite = new Sprite(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT);
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
			if ((REG_P1 & KEY_LEFT) == 0)		s->move(-1,0);
			else if ((REG_P1 & KEY_RIGHT)==0)	s->move(1,0);
			else if ((REG_P1 & KEY_UP) == 0)	s->move(0,-1);
			else if ((REG_P1 & KEY_DOWN) == 0)	s->move(0,1);
		}
		lasthit = 0; // Set to REG_P1 to stop holding of keys.

		//	Keep the display in bounds of the tilemap it draws from
		if (display.x() < 0) display.x(0);
		if (display.x() > ((32*8) - 8*30)) display.x(8*32 - 8*30);

		if (display.y() < 0) display.y(0);
		if (display.y() > ((32*8) - 8*20)) display.y(8*32 - 8*20);
		camera.updatePosition();
		
		//Rendering
		display.render();
		WaitVSync();
		UpdateObjects();

		
	}

	return 0;
}
*/