#ifndef LS_UI
#define LS_UI

class UI
{
public:
	UI(const unsigned short* background);
	void drawText(const char string[10] );

	int numberOfChanges_[2];
	int changes_[2][100][3];
	unsigned short* text_;

	const unsigned short* background_;

private:

	
};
#endif