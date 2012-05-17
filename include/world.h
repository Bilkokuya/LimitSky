#ifndef LS_WORLD
#define LS_WORLD

#include "../resource/maps/blockmap.h"

class World
{
public:
	unsigned char* maps_[2];

	World(const unsigned char* map);
	~World();

	void growPlants();

	int getObject(int x, int y);
	int getTerrain(int x, int y);

	void setTerrain(int x, int y, int block);
	void setObject(int x, int y, int block);

private:
	void addChange(int i, int x, int y, int block);
};

#endif
