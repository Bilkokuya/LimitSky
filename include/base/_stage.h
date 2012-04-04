#ifndef LS_STAGE
#define LS_STAGE

#include "sprite.h"
#include "background.h"
#include "oammanager.h"
#include "displaylist.h"

///\brief The stage processes sprites and tiles into the display memory on the screen
///			\n It contains an 128 long array of all sprites being drawn currently
///			\n It contains 4 background maps of all tiles being drawn currently
class Stage
{
public:

	Stage();

	~Stage();

	//	Accessor to the sprite list
	Sprite** sprites();

	//	Initialisation for the key parts of the GBA
	void initDisplay();
	void initBackgrounds();
	void initSprites();
	void initPalettes();

	///\brief Updates the stage data, brining in the new sprites to be used and tiles from the tilemaps
	void update();

	///\brief Sends all sprite data to the OAM and sets all relevant tiles in the backgrounds
	void draw();

	///\brief Adds a new background to the stage, max 4 on the GBA
	void addBackground(Background* background);

	//	Position Accessors
	int x();
	int y();
	void x(int xPos);
	void y(int yPos);
	void move(int dx, int dy);
	void moveTo(int x, int y);

	//	Size/Dimension Accessors
	int width();
	int height();
	void width(int w);
	void height(int h);
	void setDimensions(int width, int height);

	Background** backgrounds_;	///< The four background layers for tiles
	int backgroundsIndex_;
	DisplayList* displayList;

private:
	//static Stage* instance;

	int x_;				///< x position of the top left corner
	int y_;				///< y position of the top left corner
	int width_;			///< width of the stage to render (should be equal to screen width)
	int height_;		///< height of the stage to render (should be equal to screen height)
	Sprite** sprites_;	///< A dynamic array of sprites currently being rendered to the screen, held as pointers
	int spritesIndex_;

	OAMManager oamManager_;	///< The oamManager to allocate sprites into the correct place in VRAM

};

#endif
