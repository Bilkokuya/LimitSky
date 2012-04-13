#ifndef LS_CONTROLS
#define LS_CONTROLS

#include "../lib/gba.h"

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
extern int controlDelay[NUM_CONTROLS];
extern int controls[NUM_CONTROLS];

inline bool isControl(int key)
{
	if (controlDelay[key] > 0){
		return false;
	}else{
		return ((REG_P1 & controls[key]) == 0);
	}
}

inline void setControlDelay(int key, int time)
{
	if (time >= 0){
		controlDelay[key] = time;
	}
}

inline void updateControlDelay()
{
	for (int i = 0; i < NUM_CONTROLS; ++i){
		if (controlDelay[i] > 0){
			controlDelay[i]--;
		}
	}
}

#endif