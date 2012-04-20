#ifndef LS_WORLD
#define LS_WORLD

#include "../resource/maps/blockmap.h"

class World
{
public:
	unsigned char numberOfChanges_[2];		//	Number of changes made in this frame
	unsigned char changes_[2][1200][3];		//	Changes made this frame, held as [terrain(0) or crops(1)][changeNumber][(terrain/crops,x,y, block)]
	unsigned char* maps_[2];

	World(const unsigned char* map);
	
	void waterCrops(int x, int y);
	void harvestCrops(int x, int y);
	void plantSeeds(int x, int y);
	void tillSoil(int x, int y);
	void growPlants();

	int getObject(int x, int y);
	int getTerrain(int x, int y);

private:
	

	void setTerrain(int x, int y, int block);
	void setObject(int x, int y, int block);

	void addChange(int i, int x, int y, int block);
};

#endif