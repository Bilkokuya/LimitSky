#ifndef LS_UI
#define LS_UI

#include "player.h"

#define DRAW_TOOL_X 1
#define DRAW_TOOL_Y 18
#define DRAW_TOOL_LENGTH 10

#define DRAW_SCORE_X 18
#define DRAW_SCORE_Y 18
#define DRAW_SCORE_LENGTH 10

class UI
{
public:
	unsigned short* text_;				//	The text map for the UI
	const unsigned short* background_;	//	The background map for the UI (never changes)
	int numberOfChanges_[2];			//	Number of changes made to the UI layers this frame
	int changes_[2][600][3];			//	Array of changes that were made to the UI layers this frame
	
	UI(const unsigned short* background, Player* player);

	void update();

	void drawText(int x, int y, char* string, int length );
	
private:
	Player* player_; // Reference to the player for getting basic stats
	
};
#endif
