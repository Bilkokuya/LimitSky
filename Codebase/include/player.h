//	Copyright 2012 Gordon D Mckendrick
//	Author: Gordon D Mckendrick
//
//	Player
//		The user's player entity that tills soil, plants seeds and takes instructions from the keypad

#ifndef LS_PLAYER
#define LS_PLAYER

//	Class: Player
class Player
{
	//	States of action that player could be in
	enum PlayerState {
		IDLE,
		TILLING,
		PLANTING,
		WATERING,
		HARVESTING
	};

public:
	//	NB: Remeber to privatise these once testing is finnished
	int x, y;		//	X and Y positions in pixels
	int sprite;		//	Sprite number for accessing the 
	int animCounter;//	Prevents next action till it drops to 0
	int items[10];	//	Array of item inventory
	int tools[10];	//	Array of tool inventory
	int currentTool;//	The tool that is currently selected
	int currentItem;//	The item that is currently selected

	static const int animCounterStart = 30;	//	Constant value for the time each action takes
	PlayerState state;	//	Current state of action for the player

	Player(int xPos = 0, int yPos = 0);

	void onTick();			//	Updates the player activity each frame

	void tillSoil();		//	Tills the tile currently stood on
	void plantSeeds();		//	Plants seeds on the current tile
	void waterSoil();		//	Waters the tile currently stood on
	void harvestCrops();	//	Harvests crops at the tile being stood on

	void updatePosition();	//	Updates the sprite position, based on x and y
	void getInputs();		//	Gets keyboard inputs and processes actions
};

#endif
