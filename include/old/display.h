//	The display manager

#ifndef LS_DISPLAY
#define LS_DISPLAY

#include <list>

#include "world.h"
#include "ui.h"

#include "sprite.h"
#include "background.h"
#include "tilemap.h"
#include "camera.h"

class Display
{
public:
	Display(int x, int y, int width, int height, World* world, UI* ui, Camera* camera);

	void render();

	void registerSprite(Sprite* sprite);
	void registerSpriteToFront(Sprite* sprite);

	int x();
	int y();
	void x(int xPos);
	void y(int yPos);
	void move(int dx, int dy);
	void moveTo(int x, int y);

private:
	int x_, y_, width_, height_;	//	width and height determine the size to area of the world to render, and x,y determine the top left corner
	Background backgrounds_[4];		//	the background registers of the GBA, for easy access
	std::list<Sprite*> spriteList_;	//	a vector containing all sprites possible to render

	Camera* camera_;
	World* world_;
	UI* ui_;

	void renderSprites();
	void renderUI();

	void initDisplay();
	void initBackgrounds();
	void initPalettes();
	void initTiles();
};

#endif
