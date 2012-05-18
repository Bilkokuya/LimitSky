//	Copyright 2012 Gordon D Mckendrick
//	LimitSky
//	Player
//		The user controlled player that moves around and works in the world

#ifndef LS_PLAYER
#define LS_PLAYER

#include "sprite.h"
#include "world.h"
#include "tools.h"

class Player: public Sprite
{
public:
	int seeds_;	//	Number of seeds to plant

	Player();
	Player(int x, int y, World* world);

	void update();	//	Updates the position etc based on user input
	
	Tool* getTool();//	Returns the currently selected tool

private:
	static const int MOVE_SPEED = 1;	//	Speed the player can move at
	int direction_[2];	//	Direction facing as [x, y] where x = 1 faces right, y = 1 faces down
	World* world_;		//	World the player is walking around in
	int selectedTool_;	//	The index of the selected tool for the tools_ array
	Tool* tools_[4];	//	Tools for interacting with the world

	//	Initialisation common to both constructors
	void init();

	//	takes in user controls and works out actions based on these
	void processControls();

	//	Sets priority based on whether the player is overlapping a plant, or behind one
	void checkOverlap();

	//	Returns whether the player can move in the current direction
	bool canMove(int x, int y);

	//	Moves the player by the given amounts
	void move(int dx, int dy);

	//	ensures the player stays in the map boundary
	void keepInBounds(int xA, int yA, int xV, int yV);
};

#endif
