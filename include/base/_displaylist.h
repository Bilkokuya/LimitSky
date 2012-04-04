#ifndef LS_DISPLAYLIST
#define LS_DISPLAYLIST

#include <list>
#include "sprite.h"

class DisplayList
{
public:
	DisplayList();

	std::list<Sprite*> spriteList_;
	const unsigned short* tilemap_;

	void addSprite();

private:

};

#endif
