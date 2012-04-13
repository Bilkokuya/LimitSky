#include "../lib/gba.h"
#include "../resource/maps/map.h"
#include "../resource/tiles/terraintiles.h"
#include "../resource/tiles/palettes.h"
#include "../include/display.h"
#include "../include/sprite.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/controls.h"

int main()
{
	Display display = Display(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);

	Camera camera = Camera(SCREEN_WIDTH, SCREEN_HEIGHT, 0,0, MAPWIDTH*8, 32*8);
	display.registerCamera(&camera);
	
	World world = World(map);
	display.registerWorld(&world);

	Player player = Player(0,0, &world);
	camera.setFocus(&player);
	display.registerSprite(&player);

	LoadTile8(4,1,&terraintilesTiles[256]);

	while(true)
	{
		player.update();

		camera.updatePosition();
		display.render();

		WaitVSync();
		UpdateObjects();
		updateControlDelay();
	}
}