#include "../include/background.h"
#include "../lib/gba.h"
#include "../resource/blocks.h"

//	Base registers for memory updates, each background has memory in a consistent offset from these
//	The values for these registers were taken from Adam Sampon's gba.h file
#define BASE_REG_CONTROL REGISTER(uint16_t, 0x4000008)
#define BASE_REG_HOFFSET REGISTER(uint16_t, 0x4000010)
#define BASE_REG_VOFFSET REGISTER(uint16_t, 0x4000012)

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
	if (zPriority > 3) zPriority = 3;
	if (zPriority < 0) zPriority = 0;

	number_ = number;
	x_ = xOffset;
	y_ = yOffset;
	xOffset_ = xOffset;
	yOffset_ = yOffset;
	zPriority_ = zPriority;
	charblock_ = charblock;
	screenblock_ = screenblock;

	updateMemory();
}

void Background::updateMemory()
{
	// The memory location for the bg control register; calculated as an offset from the Base register based on which bg this is
	volatile uint16_t* controlReg = &BASE_REG_CONTROL + (number_);
	*controlReg = BG_CBB(charblock_) | BG_SBB(screenblock_) | BG_8BPP | BG_REG_32x32 | BG_PRIO(zPriority_);

	updatePosition();
}

void Background::updatePosition()
{
	// The memory location for the offsets; calculated as an offset from the Base register based on which bg this is
	volatile uint16_t* hOffsetReg = &BASE_REG_HOFFSET + (number_ * 2);
	volatile uint16_t* vOffsetReg = &BASE_REG_VOFFSET + (number_ * 2);
	*hOffsetReg = x_;
	*vOffsetReg = y_;
}

void Background::loadTile(int tilenum, const uint8_t* tiledata)
{
	LoadTile8(charblock_, tilenum, tiledata);
}

//	Returns the xOffset
int Background::x()
{
	return x_;
}

//	Returns the yOffset
int Background::y()
{
	return y_;
}

//	Sets new xOffset
void Background::x(int x)
{
	moveTo(x, y_);
}

//	Sets new yOffset
void Background::y(int y)
{
	moveTo(x_, y);
}

//	Offsets by dx and dy
void Background::move(int dx, int dy)
{
	moveTo((x_ + dx), (y_ + dy));
}

//	Offsets to position x,y
void Background::moveTo(int x, int y)
{
	x_ = (x%16) + xOffset_; // Mod by 16 for width of a block, to match with the display rendering the entire screen
	y_ = (y%16) + yOffset_;
	updatePosition();
}

//	Returns which background this is
int Background::number()
{
	return number_;
}

//	Returns the charblock
int Background::charblock()
{
	return charblock_;
}

//	Returns the screenblock
int Background::screenblock()
{
	return screenblock_;
}

//	Returns the zPriority
int Background::zPriority()
{
	return zPriority_;
}
