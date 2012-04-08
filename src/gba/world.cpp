#include "../../include/world.h"
#include "../../resource/tilemaps/tilemaps.h"

World::World()
{
	terrain_ = Tilemap(worldMap, MAP_WIDTH, MAP_HEIGHT);
	crops_ = Tilemap(0, MAP_WIDTH, MAP_HEIGHT);
}