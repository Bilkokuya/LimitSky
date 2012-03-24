///\brief Holds functionality corresponding to the REG_BG--- Registers from A.Sampson's gba.h file.
///	It is designed to give easier access to the data in these, and allow for simple initialisation in a constructor
///	There are no known issues of efficiency in using this compared to direct register access.

#ifndef LS_BG
#define LS_BG

#include "../../../lib/gba.h"

#define REG_BGCNT_BASE REGISTER(uint16_t, 0x4000008)	//	Base register of the bg control bits
#define REG_BGHOFS_BASE REGISTER(uint16_t, 0x400001C)	//	Base register of the bg horizontal offset
#define REG_BGVOFS_BASE REGISTER(uint16_t, 0x4000012)	//	Base register of the bg vertical offset

///\brief Represents an entire background register for the display
///		with simple functions for easy access to contained information
class GBATilemap
{
public:
	///\brief Initialises this BG, using standard charblock and screenblock numbering
	///\param bgNumber A number between 0 and 3, for which background layer this is
	///\param xOff The starting horizontal offset to the left
	///\param yOff The starting vertical offset, downwards
	///\warning bgNumbers out of the 0->3 range are placed at the ends of this range to avoid running off memory
	GBATilemap(int bgNumber, int xOff=0, int yOff=0)
	{
		init(bgNumber,xOff,yOff,bgNumber,30-bgNumber);
	}

	///\brief Initialises this BG, with specified charblock and screenblock numbering
	///\param bgNumber A number between 0 and 3, for which background layer this is
	///\param xOff The starting horizontal offset to the left
	///\param yOff The starting vertical offset, downwards
	///\param charblock the charblock to be used for this background
	///\param screenblock the screenblock to be used for this background
	///\warning bgNumbers and charblocks are forced into the range 0->3, use charblock 0 first and ascend.
	///\warning screenblocks are forced into the range 30->0; use screenblock 30 first and then descend.
	GBATilemap(int bgNumber, int xOff, int yOff, int charblock, int screenblock)
	{
		init(bgNumber,xOff,yOff,charblock,screenblock);
	}

	///\brief Sets the offset of this BG in absolute terms
	///\param xOff the x offset of this BG, to the left
	///\param yOff the y offset of this BG, downwards
	void setOffset(int xOff, int yOff)
	{
		x = xOff;
		y = yOff;

		updateOffset();
	}

	///\brief Offsets this BG, relative to where it is
	///\param dx the offset to be added to the left
	///\param dy the offset to be added downwards
	void offset(int dx, int dy)
	{
		x += dx;
		y += dy;

		updateOffset();
	}

	///\brief Getter for the current x value
	int X() { return x; }

	///\brief Getter for the current y value
	int Y() { return y; }

private:
	volatile unsigned short* control;	///< Pointer to the control Register that specifies the charblock used etc.
	volatile unsigned short* hOffset;	///< Pointer to the Horizontal Offset register for this background
	volatile unsigned short* vOffset;	///< Pointer to the Vertical Offset register for this background
	int x,y;							///< Current x and y offsets

	///\brief Initialises the registers
	///	Params are all from constructor, check there for definition
	void init(int bgNumber, int xOff, int yOff, int charblock, int screenblock)
	{
		//	Ensure values are within bounds
		if (bgNumber > 3) bgNumber = 3;
		if (bgNumber < 0) bgNumber = 0;
		if (charblock < 0) charblock = 0;
		if (charblock > 3) charblock = 3;
		if (screenblock < 0) screenblock = 0;
		if (screenblock > 30) screenblock = 30;

		//	Each new background register is offset by 0x1 from the previous one (the same as offsetting by the bgNumber), while the offset registers have double spacing
		control = &REG_BGCNT_BASE + bgNumber;
		hOffset = &REG_BGHOFS_BASE + (2*bgNumber);
		vOffset = &REG_BGVOFS_BASE + (2*bgNumber);

		//	Initialise the controls and starting offset
		*control = BG_CBB(charblock) | BG_SBB(screenblock) | BG_8BPP | BG_REG_32x32;
		setOffset(xOff,yOff);
	}

	///\brief Updates the offset registers to the current x and y values
	///			To be called straight after any changes to x or y are made.
	void updateOffset()
	{
		*hOffset = x;
		*vOffset = y;
	}
};

#undef REG_BGCNT_BASE
#undef REG_BGHOFS_BASE
#undef REG_BGVOFS_BASE

#endif