#include "../../lib/gba/gba.h"
#include "../../include/base/background.h"
#include "../../include/base/stage.h"
#include "../../resource/tiles/tiles.h"

Stage stage = Stage();

int main()
{
	//	Set basic background colour to orange
	SetPaletteBG(0,RGB(30,15,0));
	SetPaletteBG(1,RGB(30,30,30));
	
	for (int i = 0; i < 4; ++i){
		stage.backgrounds_[i] -> loadTile(1,tiles[0]);
		stage.backgrounds_[i] -> loadTile(2,tiles[1]);
	}

	for (int i = 0; i < 4; ++i){
		stage.backgrounds_[i] -> setTile(3,3,1);
	}

	stage.update();

	while(true);
}
