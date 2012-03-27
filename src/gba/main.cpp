#include "../../lib/gba/gba.h"
#include "../../include\gba\GBABackground.h"

GBABackground backgrounds[4] = {
	GBABackground(0,0,0),
	GBABackground(1,0,0),
	GBABackground(2,0,0),
	GBABackground(3,0,5)
};

int main()
{
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;

	//	Set basic background colour to orange
	SetPaletteBG(0,RGB(30,15,0));

	while(true);
}