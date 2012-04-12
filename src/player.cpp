#include "../include/player.h"
#include "../include/controls.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

Player::Player(): Sprite()
{	
}


Player::Player(int x, int y, World* world): Sprite(x,y,0,0,1,0)
{
	world_ = world;
}


void Player::update()
{
	processControls();
}


void Player::processControls()
{
	if (isControl(MOVE_RIGHT)){
		move( MOVE_SPEED, 0 );
		direction_[0] = 1;
		direction_[1] = 0;

	}else if (isControl(MOVE_LEFT)){
		move( -MOVE_SPEED, 0 );
		direction_[0] = -1;
		direction_[1] = 0;

	}else if (isControl(MOVE_UP)){
		move( 0 , -MOVE_SPEED );
		direction_[0] = 0;
		direction_[1] = -1;

	}else if (isControl(MOVE_DOWN)){
		move( 0 , MOVE_SPEED );
		direction_[0] = 0;
		direction_[1] = 1;

	}

	if (isControl(INTERACT)){
	

	}else if (isControl(USE_TOOL)){
		world_->tillSoil(((x_/16) + direction_[0])*2, ((y_/16) + direction_[1])*2);

	}
}

