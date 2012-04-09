#ifndef LS_WORLD
#define LS_WORLD

#include "tilemap.h"

class World
{
public:
	World();
	
	const unsigned short* terrain_;
	unsigned short* terrainChanges_;

	const unsigned short* crops_;
	unsigned short* cropsChanges_;

private:

};

#endif