#ifndef LS_DISPLAYLIST
#define LS_DISPLAYLIST

#include <list>

class DisplayList
{
public:
	std::list<Sprite*> spriteList_;
	int* tilemap[4][32][32];

	void addSprite();

private:

};
#endif