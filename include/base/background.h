
#ifndef LS_BACKGROUND
#define LS_BACKGROUND

class Background
{
public:
	Background();

	Background(int number, int xOffset = 0, int yOffset = 0, int zPriority = 0);
	
	Background(int number, int xOffset, int yOffset, int zPriority, int charblock, int screenblock);

	void setTile(int x, int y, int tile);
	void loadTile(int tilenum, const unsigned char* tiledata);

private:
	int number_;
	int x_;
	int y_;
	int charblock_;
	int screenblock_;
	int zPriority_;

	void init(int number, int xOffset, int yOffset, int zPriority, int charblock, int screenblock);
	void updateMemory();
};

#endif