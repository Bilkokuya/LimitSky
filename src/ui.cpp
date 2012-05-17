#include "../include/ui.h"
#include <cstdio>
#include <cstring>

UI::UI(const unsigned short* background, Player* player)
{
	background_ = background;
	player_ = player;

	text_ = new unsigned short[600];
	for (int i = 0; i < 600; ++i){
		text_[i] = 0;
	}
}

void UI::update()
{
	char toolTextReset[DRAW_TOOL_LENGTH] = {0};
	char scoreTextReset[DRAW_SCORE_LENGTH] = {0};
	char seedsText[DRAW_SCORE_LENGTH];
	char seedsNumText[3];
	std::strcpy(seedsText, "Seeds: ");
	std::sprintf(seedsNumText, "%d", player_->seeds_);
	std::strcat(seedsText, seedsNumText);

	drawText(DRAW_TOOL_X, DRAW_TOOL_Y, toolTextReset, DRAW_TOOL_LENGTH); // clear tool text
	drawText(DRAW_SCORE_X, DRAW_SCORE_Y, scoreTextReset, DRAW_SCORE_LENGTH); // clear score text

	//	Draw the text for the current tool
	drawText(DRAW_TOOL_X, DRAW_TOOL_Y, player_->getTool()->name(), player_->getTool()->nameLength());
	drawText(DRAW_SCORE_X, DRAW_SCORE_Y, seedsText, DRAW_SCORE_LENGTH);
}

void UI::drawText(int x, int y, char* string, int length)
{
	for (int i = 0; i < length; ++i){
		changes_[1][numberOfChanges_[1]][0] = x + i;
		changes_[1][numberOfChanges_[1]][1] = y;
		changes_[1][numberOfChanges_[1]][2] = string[i];
		numberOfChanges_[1]++;
	}
}
