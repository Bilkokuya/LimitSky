#include "../include/ui.h"

UI::UI(const unsigned short* background)
{
	background_ = background;

	text_ = new unsigned short[600];
	for (int i = 0; i < 600; ++i){
		text_[i] = 0;
	}
}


void UI::drawText(const char string[10])
{
	for (int i = 0; i < 10; ++i){
		changes_[1][numberOfChanges_[1]][0] = i;
		changes_[1][numberOfChanges_[1]][1] = 18;
		changes_[1][numberOfChanges_[1]][2] = string[i];
		numberOfChanges_[1]++;
	}
}