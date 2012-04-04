#ifndef LS_OAM_MANAGER
#define LS_OAM_MANAGER

#include "sprite.h"

class OAMManager
{
public:
	///\brief Default constructor
	OAMManager();

	///\brief Draws the given sprite into OAM Memory
	void drawSprite(int index, Sprite* sprite);

private:

};

#endif
