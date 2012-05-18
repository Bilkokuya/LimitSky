#include "../lib/gba.h"
#include "../resource/maps/blockmap.h"
#include "../resource/tiles/terraintiles.h"
#include "../resource/tiles/palettes.h"
#include "../include/display.h"
#include "../include/sprite.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/controls.h"

#define FRAMES_PER_SEC 30

void updateDayNightCycle(int &time, int *transform, Display* display, World * world);

int main()
{
	Display display(0,0,SCREEN_WIDTH,SCREEN_HEIGHT); // The main display that renders to the screen, initialises display registers

	Camera camera(SCREEN_WIDTH, SCREEN_HEIGHT, 0,0, MAPWIDTH*8, (32-20)*8); // Main camera determining where the display renders
	display.registerCamera(&camera);
	
	World world(map); // World map data for the player to move around in
	display.registerWorld(&world);

	Player player(20,20, &world); // The user controlled player object
	camera.setFocus(&player);
	display.registerSprite(&player);

	UI ui(uiBackground, &player); // UI overlay for text output
	display.registerUI(&ui);


	int time = 1; // Time that has passed in ticks, for day/night sequences
	int nightColourTransform[3] = {0}; // Colour transforms for day->night cycles [Red, Green, Blue]

	// Main update loop
	while(true)
	{
		player.update();

		updateDayNightCycle(time, nightColourTransform, &display, &world);

		camera.updatePosition();
		ui.update();
		display.update();
		display.render();

		updateControlDelay();

		WaitVSync();
		UpdateObjects();

		++time;
	}
}


//	Updates the day and night logic
//	Shifts colours to dark blue, to show night
//	Calls the world to grow all plants etc. each new day.
void updateDayNightCycle(int &time, int *transform, Display* display, World * world)
{

	//	Add a lag time where it's day with no transform
	if ( time > 60*FRAMES_PER_SEC){

		// Change the colours every second
		if ( (time%FRAMES_PER_SEC) == 0){
			transform[0] ++;
			transform[1] ++;
			transform[2] = 0;

			//	Limit the amount of the transform to avoid extreme colouring
			for (int i = 0; i < 3; ++i){
				if (transform[i] > 10) transform[i] = 10;
				if (transform[i] < -10) transform[i] = -10;
			}

			display->transformPalette( transform );
		}
	}

	//	If the night has ended, reset the transforms and tell the world to grow all plants
	if (time > 90*FRAMES_PER_SEC){
		world->growPlants();
		time = 0;
		transform[0] = 0;
		transform[1] = 0;
		transform[2] = 0;
		display->transformPalette( transform );
	}
}