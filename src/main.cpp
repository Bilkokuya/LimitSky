#include "../lib/gba.h"
#include "../resource/maps/map.h"
#include "../resource/tiles/terraintiles.h"
#include "../resource/tiles/palettes.h"
#include "../include/display.h"
#include "../include/sprite.h"
#include "../include/player.h"

bool isDown(int key);

int main()
{
	Display display = Display(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);

	Camera camera = Camera(SCREEN_WIDTH, SCREEN_HEIGHT, 0,0, MAPWIDTH*8, 32*8);
	display.registerCamera(&camera);
	
	Player player = Player(0,0);
	camera.setFocus(&player);
	display.registerSprite(&player);

	LoadTile8(4,1,&terraintilesTiles[256]);

	while(true)
	{
		//	Controls
		if (isDown(KEY_RIGHT)){
			player.move(1,0);

		}else if (isDown(KEY_LEFT)){
			player.move(-1,0);
		} 
		if (isDown(KEY_UP)){
			player.move(0,-1);

		}else if (isDown(KEY_DOWN)){
			player.move(0,1);
		}

		camera.updatePosition();
		display.render();

		WaitVSync();
		UpdateObjects();
	}
}

bool isDown(int key)
{
	return ((REG_P1 & key) == 0);
}
