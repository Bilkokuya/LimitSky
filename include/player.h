#ifndef LS_PLAYER
#define LS_PLAYER

#include "sprite.h"
#include "world.h"

class Player: public Sprite
{
public:
	Player();
	Player(int x, int y, World* world);

	void update();


private:
	static const int MOVE_SPEED = 1;
	int tool_;
	int direction_[2];
	World* world_;

	void processControls();

};

#endif
