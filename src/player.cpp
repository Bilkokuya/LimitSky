#include "../include/player.h"
#include "../include/controls.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

Player::Player(): Sprite()
{
	tool_ = 0;
}


Player::Player(int x, int y, World* world): Sprite(x,y,0,0,2,2)
{
	world_ = world;
	tool_ = 0;
}


void Player::update()
{
	processControls();
	checkOverlap();
}

void Player::checkOverlap()
{
	if (world_->getObject(((x_/16) + direction_[0])*2, ((y_/16) + direction_[1])*2) != 0){
		zPriority_ = 3;
	}else{
		zPriority_ = 2;
	}
}

bool Player::canMove(int dx, int dy)
{
	if (world_->getObject(((x_+dx)/16)*2, (((y_+dy)/16)*2)) != 0){
		return false;
	}else{
		return true;
	}
}

void Player::move(int dx, int dy)
{
	if (canMove(dx, dy)){
		Sprite::move(dx, dy);
	}
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

	if (isControl(NEXT_TOOL)){
		++tool_;
		if (tool_ > 3) tool_ = 0;
		setControlDelay(NEXT_TOOL, 20);
	}

	if (isControl(INTERACT)){
	

	}else if (isControl(USE_TOOL)){
		if (tool_ == 0){
			world_->tillSoil(((x_/16) + direction_[0])*2, ((y_/16) + direction_[1])*2);
			setControlDelay(USE_TOOL, 20);

		}else if (tool_ == 1){
			world_->plantSeeds(((x_/16) + direction_[0])*2, ((y_/16) + direction_[1])*2);
			setControlDelay(USE_TOOL, 20);

		}else if (tool_ == 2){
			world_->waterCrops(((x_/16) + direction_[0])*2, ((y_/16) + direction_[1])*2);
			setControlDelay(USE_TOOL, 20);

		}else if (tool_ == 3){
			world_->harvestCrops(((x_/16) + direction_[0])*2, ((y_/16) + direction_[1])*2);
			setControlDelay(USE_TOOL, 20);
		}
	}

	
}

