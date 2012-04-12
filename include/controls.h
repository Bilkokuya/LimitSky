#ifndef LS_CONTROLS
#define LS_CONTROLS

#include "../lib/gba.h"

#define MOVE_UP KEY_UP
#define MOVE_DOWN KEY_DOWN
#define MOVE_LEFT KEY_LEFT
#define MOVE_RIGHT KEY_RIGHT
#define NEXT_TOOL KEY_R
#define USE_TOOL KEY_B
#define INTERACT KEY_A
#define PAUSE KEY_START
#define OPEN_MAP KEY_SELECT

inline bool isControl(int key)
{
	return ((REG_P1 & key) == 0);
}

#endif