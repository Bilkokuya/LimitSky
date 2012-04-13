#include "../include/world.h"
#include "../resource/blocks.h"

World::World(const unsigned char* map)
{
	maps_[0] = new unsigned char[MAPWIDTH * MAPHEIGHT];
	maps_[1] = new unsigned char[MAPWIDTH * MAPHEIGHT];

	for (int i = 0; i < MAPWIDTH*MAPHEIGHT; ++i){
		maps_[0][i] = map[i];
		maps_[1][i] = 0;
	}
}

void World::tillSoil(int x, int y)
{
	int block = 0;
	switch (getTerrain(x,y)){
		case 0: block = 1; break;
		case 2: block = 3; break;
		case 4: block = 4; break;
		default: return;
	}

	setTerrain(x, y, block);
}

void World::waterCrops(int x, int y)
{
	int block = 0;
	switch (getTerrain(x,y)){
		case 2: block = 2; break;
		case 6: block = 4; break;
		default: return;
	}

	setTerrain(x, y, block);
}

void World::harvestCrops(int x, int y)
{
	setObject(x, y, 0);
}

void World::plantSeeds(int x, int y)
{
	setObject(x, y, 1);
}

int World::getObject(int x, int y)
{
	return (maps_[1][y*MAPWIDTH + x]);
}

int World::getTerrain(int x, int y)
{
	return (maps_[0][y*MAPWIDTH + x]);
}

void World::setTerrain(int x, int y, int block)
{
	addChange(0, x, y, block);
}

void World::setObject(int x, int y, int block)
{
	addChange(1, x, y, block);

}

void World::addChange(int i, int x, int y, int block)
{
	changes_[i][numberOfChanges_[i]][0] = x;
	changes_[i][numberOfChanges_[i]][1] = y;
	changes_[i][numberOfChanges_[i]][2] = block;
	numberOfChanges_[i]++;

	maps_[i][y*MAPWIDTH + x] = blocks[block].tile_;
	maps_[i][y*MAPWIDTH + x+1] = blocks[block].tile_+1;
	maps_[i][(y+1)*MAPWIDTH + x] = blocks[block].tile_ + 16;
	maps_[i][(y+1)*MAPWIDTH + x+1] = blocks[block].tile_ + 17;
}