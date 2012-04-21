#include "../lib/gba.h"
#include "../resource/maps/blockmap.h"
#include "../resource/tiles/terraintiles.h"
#include "../resource/tiles/palettes.h"
#include "../include/display.h"
#include "../include/sprite.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/controls.h"

int main()
{
	Display display(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);

	Camera camera(SCREEN_WIDTH, SCREEN_HEIGHT, 0,0, MAPWIDTH*8, (32-20)*8);
	display.registerCamera(&camera);
	
	World world(map);
	display.registerWorld(&world);

	UI ui(uiBackground);
	display.registerUI(&ui);

	Player player(20,20, &world, &ui);
	camera.setFocus(&player);
	display.registerSprite(&player);

	//	refactor these idiotic time transformation things
	//	develop a proper - reliable time system
	int trans[3] = {0};
	int time = 1;
	int k = 1;
	while(true)
	{
		player.update();

		// time control stuff needing refactored
		if ( time > (10)*30){
			if ( (time%30) == 0){
				trans[0] += k;
				trans[1] += k;
				trans[2] = 0;
				for (int i = 0; i < 3; ++i){
					if (trans[i] > 10) trans[i] = 10;
					if (trans[i] < -10) trans[i] = -10;
				}
				display.transformPalette( trans );
			}
		}
		if (time > (30)*30){
			world.growPlants();
			time = 0;
			trans[0] = 0;
			trans[1] = 0;
			trans[2] = 0;
			display.transformPalette( trans );
		}//end of messy time controls

		camera.updatePosition();
		display.update();
		updateControlDelay();
		display.render();

		WaitVSync();
		UpdateObjects();

		++time;
	}
}