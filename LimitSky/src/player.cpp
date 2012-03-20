//
//
//
//

#include "player.h"
#include "util.h"
#include "../lib/gba.h"

//	Constructor
Player::Player(int xPos, int yPos)
{
	x = xPos;
	y = yPos;
	sprite = 0;
	state = IDLE;

	SetObject(sprite,
		ATTR0_Y(y) | ATTR0_SHAPE(0) | ATTR0_REG | ATTR0_8BPP,
		ATTR1_X(x) | ATTR1_SIZE(0),
		ATTR2_ID8(1)
		);
}

//	Update function
void Player::onTick()
{
	//	Get the player inputs and do actions based on these
	getInputs();

	//	Update the animation counter, that determines basic states
	if (state != IDLE) {
		animCounter--;
		if (animCounter < 0){
			animCounter = 0;
			state = IDLE;
		}
	}

	//	Update the player position
	updatePosition();
}

//	Tills the tile currently stood on
void Player::tillSoil()
{
	if (state == IDLE) {
		state = TILLING;
		till(x/8,y/8);
		animCounter = animCounterStart;
	}
}	

//	Plants seeds on the current tile
void Player::plantSeeds()
{
	if (state == IDLE) {
		state = PLANTING;
		plant(x/8,y/8);
		animCounter = animCounterStart;
	}
}

//	Waters the tile currently stood on
void Player::waterSoil()
{
	if (state == IDLE) {
		state = WATERING;
		water(x/8,y/8);
		animCounter = animCounterStart;
	}
}

//	Harvests crops at the tile being stood on
void Player::harvestCrops()
{
	if (state == IDLE) {
		state = HARVESTING;
		harvest(x/8,y/8);
		animCounter = animCounterStart;
	}
}

//	Updates the sprite position, based on x and y
void Player::updatePosition()
{
	//	Ensure the movement is in the screen bounds
	if (x < 0) x = 0;
	if (x > SCREEN_WIDTH) x = SCREEN_WIDTH;
	if (y < 0) y = 0;
	if (y > SCREEN_HEIGHT) y = SCREEN_HEIGHT;

	//	Update the sprite object
	SetObjectX(sprite,x);
	SetObjectY(sprite,y);
}

//	Gets keyboard inputs and processes actions
void Player::getInputs()
{
	//	Process movement keys
	if (isKeyDown(KEY_UP))			y--;
	else if (isKeyDown (KEY_DOWN))	y++;
	else if (isKeyDown(KEY_LEFT))	x--;
	else if (isKeyDown(KEY_RIGHT))	x++;

	//	Process the action keys
	if (isKeyDown(KEY_A))		tillSoil();
	else if (isKeyDown(KEY_B))	waterSoil();
	else if (isKeyDown(KEY_L))	plantSeeds();
	else if (isKeyDown(KEY_R))	harvestCrops();
}