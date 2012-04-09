#ifndef LS_UI
#define LS_UI

#include "tilemap.h"

class UI
{
public:
	UI();

	bool hasTextChanged_;
	unsigned short* text_;

	const unsigned short* background_;

private:
};
#endif