#include "../../../include/base/background.h"
#include "../../../lib/gba/gba.h"

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
	number_ = number;
	x_ = xOffset;
	y_ = yOffset;
	zPriority_ = zPriority;
	charblock_ = charblock;
	screenblock_ = screenblock;

	updateMemory();
}

void Background::updateMemory()
{
	volatile uint16_t* controlReg = &BASE_REG_CONTROL + (number_);
	*controlReg = BG_CBB(charblock_) | BG_SBB(screenblock_) | BG_8BPP | BG_REG_32x32;

	updatePosition();
}

void Background::updatePosition()
{
	volatile uint16_t* hOffsetReg = &BASE_REG_HOFFSET + (number_ * 2);
	volatile uint16_t* vOffsetReg = &BASE_REG_VOFFSET + (number_ * 2);
	*hOffsetReg = x_;
	*vOffsetReg = y_;
}

void Background::setTile(int x, int y, int tile)
{
	SetTile(screenblock_, x, y, tile);
}

void Background::loadTile(int tile, const uint8_t* tiledata)
{
	LoadTile8(charblock_, tile, tiledata);
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
	x_ = x;
	updatePosition();
}

//	Sets new yOffset
void Background::y(int y)
{
	y_ = y;
	updatePosition();
}

//	Offsets by dx and dy
void Background::move(int dx, int dy)
{
	x_ += dx;
	y_ += dy;
	updatePosition();
}

//	Offsets to position x,y
void Background::moveTo(int x, int y)
{
	x_ = x;
	y_ = y;
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
