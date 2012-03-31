#ifndef LS_STAGE
#define LS_STAGE

#include "sprite.h"
#include "background.h"
#include "oammanager.h"

///\brief The stage processes sprites and tiles into the display memory on the screen
///			\n It contains an 128 long array of all sprites being drawn currently
///			\n It contains 4 background maps of all tiles being drawn currently
class Stage
{
public:
	///\brief Default Constructor for simple initialisation
	///		Likely to be only called once, at the start of the game
	Stage();

	///\brief Destructor ensures safe de-allocation of the sprite list memory
	///		Likely to be only called once, at the end of the game
	~Stage();

	///\brief Return the list of sprites
	Sprite** sprites();

	///\brief Initialises the Display and Loads all palette and tile data into Tile Memory (Backgrounds)
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

 	///\brief Getter: gets the current x position
	///\return The x position of the top left corner
	int x();

 	///\brief Getter: gets the current y position
	///\return The y position of the top left corner
	int y();

	///\brief Setter: sets the new x position
	///\param xPos the new x position of the top left corner
	void x(int xPos);

	///\brief Setter: sets the new y position
	///\param yPos the new y position of the top left corner
	void y(int yPos);

	///\brief Setter: moves by the specified amount
	///\param dx The amount to move the stage by in the x-direction
	///\param dy The amount to move the stage by in the y-direction
	void move(int dx, int dy);

	///\brief Setter: moves to the specified location
	///\param x The new x position of the top left corner
	///\param y The new y position of the top left corner
	void moveTo(int x, int y);


	///\brief Getter: gets the current width
	///\return The width of the stage
	int width();

	///\brief Getter: gets the current height
	///\return The height of the stage
	int height();

	///\brief Setter: sets the new width
	///\param w The new width of the stage
	void width(int w);

	///\brief Setter: sets the new height
	///\param h The new height of the stage
	void height(int h);

	///\brief Setter: sets the stage dimensions
	///\param width The new width of the stage
	///\param height The new height of the stage
	void setDimensions(int width, int height);

	Background** backgrounds_;	///< The four background layers for tiles
	int backgroundsIndex_;

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