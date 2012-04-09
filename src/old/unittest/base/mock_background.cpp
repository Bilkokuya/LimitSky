#include "base/background.h"

Background::Background()
{
}

Background::Background(int number, int xOffset, int yOffset, int zPriority)
{
	init(number, xOffset, yOffset, zPriority, number, 30-number);
}

Background::Background(int number, int xOffset, int yOffset, int zPriority, int charblock, int screenblock)
{
	init(number, xOffset, yOffset, zPriority, charblock, screenblock);
}

void Background::init(int number, int xOffset, int yOffset, int zPriority, int charblock, int screenblock)
{
	number_ = number;
	xOffset_ = xOffset;
	yOffset_ = yOffset;
	zPriority_ = zPriority;
	charblock_ = charblock;
	screenblock_ = screenblock;
}
