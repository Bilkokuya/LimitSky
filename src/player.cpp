#include "../include/player.h"
#include "../include/controls.h"

//	movement boundaries
#define MIN_X_POS 8 // 8 is half the width of the player
#define MIN_Y_POS 8
#define MAX_X_POS (MAPWIDTH*16 - 8)
#define MAX_Y_POS (MAPHEIGHT*16 - 8)

Player::Player(): Sprite()
{
	init();
}


Player::Player(int x, int y, World* world): Sprite(x,y,1,0,0,2)
{
	world_ = world;
	init();
}

//	Initialisation common to both constructors
void Player::init()
{
	seeds_ = 24; // Number of seeds you start with
	zPriority_ = 3;
	selectedTool_ = 0;
	tools_[0] = new ToolHoe(world_);
	tools_[1] = new ToolWateringCan(world_);
	tools_[2] = new ToolScythe(world_, &seeds_);
	tools_[3] = new ToolSeeds(world_, &seeds_);
}

void Player::update()
{
	processControls();
}

Tool* Player::getTool()
{
	return ( tools_[selectedTool_] );
}

bool Player::canMove(int dx, int dy)
{
	int free[2] = {0,8}; // can walk on empty, and on seeds
	int points[4][2] = { // positions on the player to test for hits
		{4,4},
		{12,4},
		{4,12},
		{12,12},
	};

	// loop throuh each set of positions to determine if it can move
	//	return true if all points are free to move, or false if any cannot
	for (int p = 0; p < 4; ++p){
		int block = world_->getObject(((x_+points[p][0]+dx)/16), (((y_+points[p][1]+dy)/16)));
		bool isFree = false;
		for (int i = 0; i < 2; ++i){
			if (block == free[i]) isFree = true;
		}
		if (!isFree) return false;
	}
	return true;
}

void Player::move(int dx, int dy)
{
	if (canMove(dx, dy)){
		Sprite::move(dx, dy);
	}

	keepInBounds(MIN_X_POS, MIN_Y_POS, MAX_X_POS, MAX_Y_POS);
}


void Player::keepInBounds(int xA, int yA, int xV, int yV)
{
	if ( x_ < xA) x_ = xA;
	if ( (x_ + 16) > xV) x_ = xV - 16;
	if ( y_ < yA) y_ = yA;
	if ( (y_ + 16) > yV) y_ = yV - 16;
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
	}

	if (isControl(INTERACT)){
		tools_[selectedTool_]->interact((((x_+8)/16) + direction_[0])*2, (((y_+8)/16) + direction_[1])*2);
		setControlDelay(INTERACT, 20);

	}else if (isControl(USE_TOOL)){
		tools_[selectedTool_]->useTool((((x_+8)/16) + direction_[0]), (((y_+8)/16) + direction_[1]));
		setControlDelay(USE_TOOL, 10);
	}
}
