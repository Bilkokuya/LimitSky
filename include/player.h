#ifndef LS_PLAYER
#define LS_PLAYER

#include "sprite.h"
#include "world.h"
#include "tools.h"

class Player: public Sprite
{
public:
	int seeds_;

	Player();
	Player(int x, int y, World* world);

	void update();
	
	Tool* getTool();

private:
	static const int MOVE_SPEED = 1;
	int selectedTool_;
	int direction_[2];
	World* world_;
	Tool* tools_[4];

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
