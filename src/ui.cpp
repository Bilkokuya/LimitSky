#include "../include/ui.h"
#include <cstdio>
#include <cstring>

UI::UI(const unsigned short* background, Player* player)
{
	background_ = background;
	player_ = player;

	//	Initialise the text layer to be blank
	text_ = new unsigned short[600];
	for (int i = 0; i < 600; ++i){
		text_[i] = 0;
	}
}

void UI::update()
{
	char toolTextReset[DRAW_TOOL_LENGTH] = {0};	//	text resets for wiping the space
	char scoreTextReset[DRAW_SCORE_LENGTH] = {0};

	char seedsText[DRAW_SCORE_LENGTH] = {0}; // fill seeds amount array
	char seedsNumText[3] = {0}; // small array to just hold the number of seeds

	//	Get the number of seeds, and put the data together in a single printable array
	int seeds = player_->seeds_;
	if (seeds > 999) seeds = 999; // only display '999' if there are more than this, but maintain the actual number for functionality.
	std::strcpy(seedsText, "Seeds: ");
	std::sprintf(seedsNumText, "%d", seeds);
	std::strcat(seedsText, seedsNumText);

	//	Wipe the existing text
	drawText(DRAW_TOOL_X, DRAW_TOOL_Y, toolTextReset, DRAW_TOOL_LENGTH); // clear tool text
	drawText(DRAW_SCORE_X, DRAW_SCORE_Y, scoreTextReset, DRAW_SCORE_LENGTH); // clear score text

	//	Draw the new text for the tool and seed amount
	drawText(DRAW_TOOL_X, DRAW_TOOL_Y, player_->getTool()->name(), player_->getTool()->nameLength());
	drawText(DRAW_SCORE_X, DRAW_SCORE_Y, seedsText, DRAW_SCORE_LENGTH);
}

void UI::drawText(int x, int y, char* string, int length)
{
	//	Draws each character from the string array, as a tile at the given position
	for (int i = 0; i < length; ++i){
		changes_[1][numberOfChanges_[1]][0] = x + i;
		changes_[1][numberOfChanges_[1]][1] = y;
		changes_[1][numberOfChanges_[1]][2] = string[i];
		numberOfChanges_[1]++;
	}
}
