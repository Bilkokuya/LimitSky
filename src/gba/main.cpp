#define TRUE 1
#define FALSE 0

#include "../../include/base/display.h"
#include "../../lib/gba/gba.h"
#include "../../include/base/sprite.h"

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

	for (int i = 0; i < 256; ++i)
		LoadTile8(4,i,tile);

	SetPaletteBG(5,0xF0F0);
	SetPaletteObj(5,0xF0F0);

	Sprite* s = new Sprite(5,10);
	s->tile(2);

	display.registerSprite(s);
	ClearObjects();

	while(true)
	{
		//Logic Updates
		if ((REG_P1 & KEY_LEFT) == 0)		s->move(-1,0);
		else if ((REG_P1 & KEY_RIGHT)==0)	s->move(1,0);
		else if ((REG_P1 & KEY_UP) == 0)	s->move(0,-1);
		else if ((REG_P1 & KEY_DOWN) == 0)	s->move(0,1);

		//Rendering
		display.render();
		WaitVSync();
		UpdateObjects();
	}

	return 0;
}
