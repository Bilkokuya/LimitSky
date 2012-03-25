#ifndef LS_DISPLAYLIST
#define LS_DISPLAYLIST
#include "sprite.h"
#include <list>

class DisplayList
{
public:
	std::list<Sprite*> spriteList;

	///\brief Adds the given sprite to the list of sprites
	///\param s A pointer to a sprite that should be added to the display list
	///\warning Alters the displaylist index in the sprite object without consideration.
	///\warning It is essential to remove the sprite from this list when it is deconstructed.
	void addSprite(Sprite* s);

	///\brief Removes the given sprite from the list of sprites
	///\param s A pointer to the sprite that will be removed.
	///\warning Will remove whichever sprite is specified by this sprite's index, regardless of equality.
	///\warning Does not delete the sprite, only removes it from the display list
	void removeSprite(Sprite* s);

	///\brief Removes the sprite at the specified index from the list of sprites
	///\param index The index of the sprite to be removed
	///\warning Does not delete the sprite, only removes it from the display list
	void removeSprite(int index);
};

#endif