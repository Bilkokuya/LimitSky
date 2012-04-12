#include "../include/world.h"

World::World(const unsigned char* map)
{
	terrain_ = new unsigned char[MAPWIDTH * MAPHEIGHT];
	crops_ = new unsigned char[MAPWIDTH * MAPHEIGHT];

	for (int i = 0; i < MAPWIDTH*MAPHEIGHT; ++i){
		terrain_[i] = map[i];
	}
}

void World::tillSoil(int x, int y)
{
	setTerrain(x, y,     1);
	setTerrain(x+1, y,   2);
	setTerrain(x, y+1,   3);
	setTerrain(x+1, y+1, 4);
}

void World::waterCrops(int x, int y)
{

}

void World::harvestCrops(int x, int y)
{
}

void World::plantSeeds(int x, int y)
{
}

int World::getObject(int x, int y)
{
	return 0;
}

int World::getTerrain(int x, int y)
{
	return 0;
}

void World::setTerrain(int x, int y, int tile)
{
	addChange(0, x, y, tile);
}

void World::setObject(int x, int y, int tile)
{
	addChange(1, x, y, tile);
}

void World::addChange(int i, int x, int y, int tile)
{
	changes_[i][numberOfChanges_[i]][0] = x;
	changes_[i][numberOfChanges_[i]][1] = y;
	changes_[i][numberOfChanges_[i]][2] = tile;
	numberOfChanges_[i]++;
}