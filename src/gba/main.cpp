#include "../../lib/gba/gba.h"
#include "../../include/base/background.h"

const uint8_t fakeTile [64] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
};

Background bgs[4] = {
		Background(0,0,0),
		Background(1,0,0),
		Background(2,0,0),
		Background(3,2,2)
	};

int main()
{
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;

	
	//	Set basic background colour to orange
	SetPaletteBG(0,RGB(30,15,0));
	SetPaletteBG(1,RGB(30,30,30));

	bgs[2].loadTile(1,fakeTile);
	bgs[3].loadTile(1,fakeTile);

	bgs[2].setTile(3,3,1);
	bgs[3].setTile(3,3,1);

	while(true);
}
