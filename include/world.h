//	Copyright 2012 Gordon D Mckendrick
//	LimitSky
//	World
//		Contains map data for the world everything interacts with

#ifndef LS_WORLD
#define LS_WORLD

#include "../resource/maps/blockmap.h"

class World
{
public:
	unsigned char* maps_[2];	//	[Terrain, Crops] maps of block data

	World(const unsigned char* map);
	~World();

	void growPlants();	//	Does all overnight processing - originally just grew the plants

	int getObject(int x, int y);	//	Returns the crop at the given x and y
	int getTerrain(int x, int y);	//	Returns the terrain at the given x and y

	void setTerrain(int x, int y, int block);	//	Sets the terrain at the given x and y to the specific terrain type
	void setObject(int x, int y, int block);	//	Sets the crop to the given type at that x and y position

private:
	void addChange(int i, int x, int y, int block);	//	Makes a new change to the maps, where i is the map to change
};

#endif
