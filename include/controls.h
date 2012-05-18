//	Copyright 2012 Gordon D Mckendrick
//	LimitSky
//	Controls
//		A simple set of functions for working with user input from GBA controls
//		Abstracts the key presses to the actions they represent, allowing easy change of controls
//		Adds easy delay functionality for preventing rapid/held key presses

#ifndef LS_CONTROLS
#define LS_CONTROLS

#include "../lib/gba.h"

//	The position in the controls array that this action's control is found
#define MOVE_UP 0
#define MOVE_DOWN 1
#define MOVE_LEFT 2
#define MOVE_RIGHT 3
#define NEXT_TOOL 4
#define USE_TOOL 5
#define INTERACT 6
#define PAUSE 7
#define OPEN_MAP 8

#define NUM_CONTROLS 9
extern int controlDelay[NUM_CONTROLS]; // Holds the delays assigned to each control
extern int controls[NUM_CONTROLS];

//	Returns true if the given control can be used/ is not in delay
inline bool isControl(int key)
{
	if (controlDelay[key] > 0){
		return false;
	}else{
		return ((REG_P1 & controls[key]) == 0);
	}
}

//	Sets the delay for a control to be used again
inline void setControlDelay(int key, int time)
{
	if (time >= 0){
		controlDelay[key] = time;
	}
}

//	Sets a control delay for movement in all directions
inline void setMovementControlDelay(int time)
{
	// Relies on movement controls being numerical sequence from MOVE_UP
	for (int i = 0; i < 4; ++i){
		setControlDelay(MOVE_UP +i, time);
	}
}

//	Reduces current delays till they become 0 (when they can be used again)
inline void updateControlDelay()
{
	for (int i = 0; i < NUM_CONTROLS; ++i){
		if (controlDelay[i] > 0){
			controlDelay[i]--;
		}
	}
}

#endif
