#ifndef LS_STAGE
#define LS_STAGE

#include "sprite.h"

///\brief The stage processes sprites and tiles into the display memory on the screen
///			\n It contains an 128 long array of all sprites being drawn currently
///			\n It contains 4 background maps of all tiles being drawn currently
class Stage
{
public:
	Sprite** sprites_;	///< An array of sprite pointers, on the heap.

	///\brief Default Constructor for simple initialisation
	///		Likely to be only called once, at the start of the game
	Stage();

	///\brief Destructor ensures safe de-allocation of the sprite list memory
	///		Likely to be only called once, at the end of the game
	~Stage();

	///\brief Return the list of sprites
	Sprite** sprites();
};

#endif