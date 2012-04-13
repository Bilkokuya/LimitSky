#ifndef LS_PLAYER
#define LS_PLAYER

#include "sprite.h"
#include "world.h"
#include "ui.h"

class Player: public Sprite
{
public:
	Player();
	Player(int x, int y, World* world, UI* ui);

	void update();
	


private:
	static const int MOVE_SPEED = 1;
	int tool_;
	int direction_[2];
	World* world_;
	UI* ui_;

	void processControls();
	void checkOverlap();
	bool canMove(int x, int y);
	void move(int dx, int dy);
	void displayTool();
};

#endif
