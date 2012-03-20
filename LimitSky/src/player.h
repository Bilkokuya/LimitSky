//
//
//
//
#ifndef LIMITSKY_PLAYER
#define LIMITSKY_PLAYER

class Player
{
	enum PlayerState {
		IDLE,
		TILLING,
		PLANTING,
		WATERING,
		HARVESTING
	};

public:
	int x, y;		//	X and Y positions in pixels
	int sprite;		//	Sprite number for accessing the 
	int animCounter;
	int items[10];	//	Array of item inventory
	int tools[10];	//	Array of tool inventory
	int currentTool;//	The tool that is currently selected
	int currentItem;//	The item that is currently selected

	static const int animCounterStart = 30;
	PlayerState state;

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