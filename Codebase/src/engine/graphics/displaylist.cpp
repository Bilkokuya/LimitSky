#include "engine\displaylist.h"
#include "engine\sprite.h"


void DisplayList::addSprite(Sprite* s)
{
	spriteList.push_front(s);
}

void DisplayList::removeSprite(int index)
{
}

void DisplayList::removeSprite(Sprite* s)
{
	spriteList.remove(s);
}


