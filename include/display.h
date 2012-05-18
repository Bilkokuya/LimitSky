//	Copyright 2012 Gordon D Mckendrick
//	LimitSky
//	Display
//		The current display system that renders all visible objects to the screen
//		Abstracts the rendering from the objects themselves and allows for efficiency gains by sequencing rendering etc.
//		Initialises the GBA display data and background objects for rendering to
//		Theoretically, on other devices, multiple instances of this could follow different cameras; allowing split screen etc.
	
#ifndef LS_DISPLAY
#define LS_DISPLAY

#include <list>

#include "sprite.h"
#include "camera.h"
#include "background.h"
#include "world.h"
#include "ui.h"

#include "../lib/gba.h"

class Display
{
public:
	Display(int x, int y, int width, int height);

	void update(); //	Updates the position to where the camera is pointing
	void render(); //	Renders the current game data to the screen

	void registerCamera(Camera* camera);		// sets which camera this display renders from
	void registerWorld(World* world);			// sets the world data that the display renders from
	void registerUI(UI* ui);					// sets the UI that will be rendered as an overlay
	void registerSprite(Sprite* sprite);		// registers a new sprite to the list of sprites to be rendered
	void registerSpriteToFront(Sprite* sprite); // registers a sprite to the front of the spritelist; guaranteeing it will be rendered if it's on screen

	void transformPalette(int* transform);	//	Transforms the current palette by the given transform[R,G,B] - relative to the original (non-transformed) palette

	//	Position accessors
	int x();
	int y();
	void x(int xPos);
	void y(int yPos);
	void move(int dx, int dy);
	void moveTo(int x, int y);

private:
	int x_, y_, width_, height_;	//	width and height determine the size to area of the world to render, and x,y determine the top left corner
	int frame;						//	The frame number that is being rendered. Increases by 1 each time a render is called; allows things to be rendered every nth render.
	std::list<Sprite*> spriteList_;	//	a vector containing all sprites possible to render
	Background bgs_[4];				//	The 4 background registers of the GBA
	Camera* camera_;				//	Current camera to render from
	World* world_;					//	World data to render
	UI* ui_;						//	UI to overlay on the scnree

	void initRegisters();	//	Initialises the display registers
	void initPalettes();	//	Initialises and loads the palette data
	void initTiles();		//	Initialises and loads the tile data

	void renderSprites();	//	Renders currently visible sprites to the screen
	void renderWorld();	//	Renders the terrain background to the screen
	void renderUI();		//	Renders the UI overlay

	void paletteTransform(int* transform, const unsigned short* originalPallete, volatile uint16_t* paletteReg);
	
	int red(uint16_t colour);	//	Returns the Red part from a GBA colour
	int green(uint16_t colour); //	Returns the Green part from a GBA colour
	int blue(uint16_t colour);	//	Returns the Blue part from a GBA colour

	void wrapInRange(int min, int max, int& i); // wraps the given int i, in range max/min (so max+1 = min)
};

#endif
