#include "../include/world.h"
#include "../resource/blocks.h"
#include <cstdlib>

World::World(const unsigned char* map)
{
	maps_[0] = new unsigned char[MAPWIDTH * MAPHEIGHT];
	maps_[1] = new unsigned char[MAPWIDTH * MAPHEIGHT];
	
	for (int i = 0; i < MAPWIDTH*MAPHEIGHT; ++i){
		maps_[0][i] = map[i];
		maps_[1][i] = 0;
	}
}

World::~World()
{
	delete[] maps_;
}

void World::growPlants()
{
	// grow all plants sitting on watered terrain
	for (int y = 0; y < MAPHEIGHT; ++y){
		for (int x = 0; x < MAPWIDTH; ++x){

			int terrain = getTerrain(x,y);
			int crop = getObject(x,y);

			//	Grow the crop if the terrain is watered+tilled
			if (terrain == 5){
				switch (crop){
					case 8: setObject(x,y,9);	break; // seeds -> sapling
					case 9: setObject(x,y,10);	break; // sapling -> white plant
					case 10: setObject(x,y,11);	break; // white plant -> pumpkin
					default: break;
				}
			}

			//	De-water terrain
			switch (terrain){
				case 3: setTerrain(x,y,2);	break;
				case 5: setTerrain(x,y,4);	break;
				default: break;
			}

			//	Additional changes for unplanted soil
			if (!crop){
				switch (terrain){
					case 4: if ((rand()%2) == 0) setTerrain(x,y, 2); break; //	Degrade half of dry and not planted soil into dirt
					case 2: if ((rand()%3) == 0) setTerrain(x,y, 1); break; //	Degrade regrow 10% of dirt into grass
				}
			}
		}
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
