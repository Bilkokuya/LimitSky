
#ifndef LS_ENGINE
#define LS_ENGINE

#include "platform.h"
#include "displaylist.h"
#include "sprite.h"
#include "tile.h"

//////////////////////////////////////////////////////////////////////
//	Temporary - please remove as soon as possible
//	Used only by the world, as it has outdated function calls
extern void SetTile(int a, int b, int c, int d);
//////////////////////////////////////////////////////////////////////

///brief The platform being linked into the engine for development
///		Takes calls from the engine and processes them for the specific platform hardware
extern Platform platform;

///\brief The display list that all drawn objects are sent to
extern DisplayList displayList;


///\brief Sets the platform for development
///\param p The platform to set up the engine for.
extern void setPlatform(Platform p);

///\brief Adds this sprite to the displaylist of sprites
///\param s The sprite to be added into the display list
extern void newSprite(Sprite s);

///\brief Adds a new tile into the game
///\param t The tile to be added
extern void newTile(Tile t);


#endif