#include "../lib/gba.h"
#include "output.h"
#include "tiles.h"

int main()
{
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
	REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;
	REG_BG1CNT = BG_CBB(0) | BG_SBB(29) | BG_8BPP | BG_REG_32x32;
	REG_BG2CNT = BG_CBB(0) | BG_SBB(28) | BG_8BPP | BG_REG_32x32;
	REG_BG3CNT = BG_CBB(0) | BG_SBB(27) | BG_8BPP | BG_REG_32x32;

	for (int i = 0; i < TILECOUNT; ++i){
		LoadTile8(0, i, &tiles[i*64]);
	}
	for (int i = 0; i < PALETTECOUNT; ++i){
		SetPaletteBG(i, palette[i]);
	}

	for (int i = 0; i < 20; ++i){
		for (int j = 0; j < 31; ++j){
			SetTile(30, j,i, map[j*MAPWIDTH + i]);
		}
	}

	int xOff = 0;
	int nextCol = 31;
	int lastCol = 0;
	int yOff = 0;
	int direction = 1;
	while(true)
	{
		bool moving = false;

		if ((REG_P1 & KEY_LEFT) == 0){
			moving = true;
			direction = -1;

		}else if ((REG_P1 & KEY_RIGHT) == 0){
			moving = true;
			direction = 1;
		}

		if ((xOff >= 8*MAPWIDTH) && (direction == 1)) direction = 0;
		if ((xOff <= 0) && (direction == -1)) direction = 0;

		if (moving){
			xOff += direction;
		}

		if (moving){
			if ( (xOff%8) == 0){
			
				if (direction > 0){
					for (int i = 0; i < 20; ++i){
						SetTile(30, nextCol, i, map[(i*MAPWIDTH) + (xOff/8)+30]);
					}
					nextCol++;
					lastCol++;

				}else if (direction < 0){
					for (int i = 0; i < 20; ++i){
						SetTile(30, lastCol-2, i, map[(i*MAPWIDTH) + (xOff/8)-2]);
					}
					nextCol--;
					lastCol--;
				}
			}
		}

		

		nextCol = nextCol%32;
		lastCol = lastCol%32;

		

		WaitVSync();
		REG_BG0HOFS = xOff;
	}
}