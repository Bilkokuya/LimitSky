#ifndef LS_OAM_MANAGER
#define LS_OAM_MANAGER

class OAMManager
{
public:
	///\brief Default constructor
	OAMManager();

	///\brief Draws the given sprite into OAM Memory
	void drawSprite(int index, Sprite* sprite);

	///\brief Hides the given sprite if visible
	void hideSprite(int index);

	///\brief Shows the given sprite if hidden
	void showSprite(int index);

	///\brief Sets the given sprite's z-priority
	void setPriority(int index, int priority);

private:

};

#endif
