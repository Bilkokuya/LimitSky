#include "../../lib/gba/gba.h"
#include "../../include/base/background.h"
#include "../../include/base/stage.h"

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

Stage stage = Stage();

int main()
{
	//	Set basic background colour to orange
	SetPaletteBG(0,RGB(30,15,0));
	SetPaletteBG(1,RGB(30,30,30));
	
	for (int i = 0; i < 4; ++i){
		stage.backgrounds_[i] -> loadTile(1,fakeTile);
	}

	for (int i = 0; i < 4; ++i){
		stage.backgrounds_[i] -> setTile(3,3,1);
	}

	while(true);
}
