//	The display manager

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

	void render();
	void update();

	void registerCamera(Camera* camera);
	void registerWorld(World* world);
	void registerUI(UI* ui);
	void registerSprite(Sprite* sprite);
	void registerSpriteToFront(Sprite* sprite);

	void loadPalette(const uint16_t* palette);
	void transformPalette(int* transform);

	int red(uint16_t colour);
	int green(uint16_t colour);
	int blue(uint16_t colour);

	int x();
	int y();
	void x(int xPos);
	void y(int yPos);
	void move(int dx, int dy);
	void moveTo(int x, int y);

private:
	int x_, y_, width_, height_;	//	width and height determine the size to area of the world to render, and x,y determine the top left corner
	std::list<Sprite*> spriteList_;	//	a vector containing all sprites possible to render
	Background bgs_[4];			//	The 4 background registers of the GBA
	Camera* camera_;
	World* world_;
	UI* ui_;
	const uint16_t* palette_;

	int lBuff_, rBuff_;
	int left_, right_;


	void renderSprites();
	void renderTerrain();
	void renderCrops();
	void renderUI();

	void initRegisters();
	void initPalettes();
	void initTiles();

	void wrapInRange(int min, int max, int& i);
};

#endif
