#include "../include/player.h"
#include "../include/controls.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

Player::Player(): Sprite()
{
	zPriority_ = 3;
	selectedTool_ = 0;
	tools_[0] = new ToolHoe(world_);
	tools_[1] = new ToolWateringCan(world_);
	tools_[2] = new ToolScythe(world_);
	tools_[3] = new ToolSeeds(world_);
}


Player::Player(int x, int y, World* world, UI* ui): Sprite(x,y,1,0,0,2)
{
	world_ = world;
	ui_ = ui;

	zPriority_ = 3;

	selectedTool_ = 0;
	tools_[0] = new ToolHoe(world_);
	tools_[1] = new ToolWateringCan(world_);
	tools_[2] = new ToolSeeds(world_);
	tools_[3] = new ToolScythe(world_);

	displayTool();
}


void Player::update()
{
	processControls();
}

bool Player::canMove(int dx, int dy)
{
	int free[2] = {0,8}; // can walk on empty, and on seeds
	int points[4][2] = {
		{4,4},
		{12,4},
		{4,12},
		{12,12},
	};
	for (int p = 0; p < 4; ++p){
		int block = world_->getObject(((x_+points[p][0]+dx)/16), (((y_+points[p][1]+dy)/16)));
		bool b = false;
		for (int i = 0; i < 2; ++i){
			if (block == free[i]) b = true;
		}
		if (!b) return false;
	}
	return true;
}

void Player::move(int dx, int dy)
{
	if (canMove(dx, dy)){
		Sprite::move(dx, dy);
	}

	keepInBounds(8,8,MAPWIDTH*16 - 8, MAPHEIGHT*16 - 8);
}

void Player::keepInBounds(int xA, int yA, int xV, int yV)
{
	if ( x_ < xA) x_ = xA;
	if ( (x_+16) > xV) x_ = xV - 8;
	if ( y_ < yA) y_ = yA;
	if ( (y_ + 16) > yV) y_ = yV - 8;
}


void Player::processControls()
{
	if (isControl(MOVE_RIGHT)){
		move( MOVE_SPEED, 0 );
		direction_[0] = 1;
		direction_[1] = 0;
		tileNum_ = 4;

	}else if (isControl(MOVE_LEFT)){
		move( -MOVE_SPEED, 0 );
		direction_[0] = -1;
		direction_[1] = 0;
		tileNum_ = 12;

	}else if (isControl(MOVE_UP)){
		move( 0 , -MOVE_SPEED );
		direction_[0] = 0;
		direction_[1] = -1;
		tileNum_ = 8;

	}else if (isControl(MOVE_DOWN)){
		move( 0 , MOVE_SPEED );
		direction_[0] = 0;
		direction_[1] = 1;
		tileNum_ = 0;

	}

	if (isControl(NEXT_TOOL)){
		++selectedTool_;
		if (selectedTool_ > 3) selectedTool_ = 0;
		setControlDelay(NEXT_TOOL, 20);
		displayTool();
	}

	if (isControl(INTERACT)){
		tools_[selectedTool_]->interact((((x_+8)/16) + direction_[0])*2, (((y_+8)/16) + direction_[1])*2);
		setControlDelay(INTERACT, 20);

	}else if (isControl(USE_TOOL)){
		tools_[selectedTool_]->useTool((((x_+8)/16) + direction_[0]), (((y_+8)/16) + direction_[1]));
		setControlDelay(USE_TOOL, 10);
	}

	
}

void Player::displayTool()
{
	switch (selectedTool_){
		case 0: ui_->drawText("Tilling   "); break;
		case 1: ui_->drawText("Watering  "); break;
		case 2: ui_->drawText("Planting  "); break;
		case 3: ui_->drawText("Harvesting"); break;
		default: return;
	}
}