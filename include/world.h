#ifndef LS_WORLD
#define LS_WORLD

#include "tilemap.h"

class World
{
public:
	World();
	
	Tilemap terrain_;
	Tilemap crops_;
private:

};

#endif