#include "../../lib/gba/gba.h"
#include "../../include/base/background.h"
#include "../../include/base/stage.h"
#include "../../resource/tiles/tiles.h"

Stage stage = Stage();

int main()
{
	//	Set basic background colour to orange
	for (int i = 0; i < 6; i++){
		SetPaletteBG(i, palette[i]);
	}
	
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; j++){
			stage.backgrounds_[i] -> loadTile(j,tiles[j]);
		}
	}

	for (int i = 0; i < 4; ++i){
		stage.backgrounds_[i] -> setTile(3,3,2);
	}

	stage.update();

	while(true);
}
