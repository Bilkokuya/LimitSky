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


Player::Player(int x, int y, World* world, UI* ui): Sprite(x,y,0,0,2,2)
{
	world_ = world;
	ui_ = ui;

	zPriority_ = 3;

	selectedTool_ = 0;
	tools_[0] = new ToolHoe(world_);
	tools_[1] = new ToolWateringCan(world_);
	tools_[2] = new ToolScythe(world_);
	tools_[3] = new ToolSeeds(world_);

	displayTool();
}


void Player::update()
{
	processControls();
}

bool Player::canMove(int dx, int dy)
{
	if ((world_->getObject(((x_+8+dx)/16)*2, (((y_+8+dy)/16)*2)) != 0)
		||
		(world_->getObject(((x_+dx)/16)*2, (((y_+8+dy)/16)*2)) != 0)
		||
		(world_->getObject(((x_+8+dx)/16)*2, (((y_+dy)/16)*2)) != 0)
		||
		(world_->getObject(((x_+dx)/16)*2, (((y_+dy)/16)*2)) != 0)){
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
		++selectedTool_;
		if (selectedTool_ > 3) selectedTool_ = 0;
		setControlDelay(NEXT_TOOL, 20);
		displayTool();
	}

	if (isControl(INTERACT)){
		tools_[selectedTool_]->interact((((x_+4)/16) + direction_[0])*2, (((y_+4)/16) + direction_[1])*2);
		setControlDelay(INTERACT, 20);

	}else if (isControl(USE_TOOL)){
		tools_[selectedTool_]->useTool((((x_+4)/16) + direction_[0])*2, (((y_+4)/16) + direction_[1])*2);
		setControlDelay(USE_TOOL, 20);
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