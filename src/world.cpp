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

void World::growPlants()
{
	// grow all plants sitting on watered terrain
	for (int y = 0; y < MAPHEIGHT; ++y){
		for (int x = 0; x < MAPWIDTH; ++x){
			int terrain = getTerrain(x,y);
			int crop = getObject(x,y);

			switch (terrain){
				case 3: setTerrain(x,y,2);break;
				case 5: setTerrain(x,y,4);break;
				default: break;
			}
			if (terrain == 5){
				switch (crop){
					case 8: setObject(x,y,9);break;
					case 9: setObject(x,y,10);break;
					case 10: setObject(x,y,11);break;
					default: break;
				}
			}
		}
	}

	// de-water all terrain
}

void World::tillSoil(int x, int y)
{
	int block = 0;
	switch (getTerrain(x,y)){
		case 1: block = 2; break;
		case 2: block = 4; break;
		case 3: block = 5; break;
		default: return;
	}

	setTerrain(x, y, block);
}

void World::waterCrops(int x, int y)
{
	int block = 0;
	switch (getTerrain(x,y)){
		case 2: block = 3; break;
		case 4: block = 5; break;
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
	if (((getTerrain(x,y) == 4) || (getTerrain(x,y) == 5))
		&& (getObject(x,y) == 0)){
		setObject(x, y, 8);
	}
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
	maps_[i][y*MAPWIDTH + x] = block;
}