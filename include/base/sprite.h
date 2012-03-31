#ifndef LS_SPRITE
#define LS_SPRITE

///\brief A 2D sprite graphic that can be moved, rotated and scaled
///		Is non specific to any platform; making calls to the engine once a platform has been created
class Sprite
{
public:
	///\brief Default Constructor for array use.
	///\warning	Does not automatically add to the DisplayList.
	Sprite();

	///\brief Constructor with simple initialised values
	///\warning Will automatically be added to the DisplayList
	Sprite(int xPos, int yPos, int angle = 0, float xScale = 1, float yScale = 1);

	///\brief Getter: For the x co-ordinate of this Sprite
	///\return The x co-ordinate as an int
	int	x();

	///\brief Getter: For the y co-ordinate of this Sprite
	///\return The y co-ordinate as an int
	int	y();

	///\brief Setter: Sets the x co-ordinate
	///\param xPosition The new x co-ordinate to be set
	void x(int xPosition);

	///\brief Setter: Sets the y co-ordinate
	///\param yPosition The new y co-ordinate to be set
	void y(int yPosition);

	///\brief Setter: Moves the sprite within the world
	///\param dx The amount to move the sprite in the x direction
	///\param dy The amount to move the sprite in the y direction
	void move(int dx, int dy);

	///\brief Setter: Moves the sprite to this absolute co-ordinate
	///\param x the new x co-ordinate of the Sprite
	///\param y the new y co-ordinate of the Sprite
	void moveTo(int x, int y);

	///\brief Getter: Gets the current rotation in degrees
	///\return The angle of rotation with the positive x-axis of this Sprite, in degrees
	int	rotation();

	///\brief Setter: Rotates the sprite by the given angle
	///\param dw The amount to rotate the sprite anti-clockwise in degrees
	void rotate(int dw);

	///\brief Setter: Sets the rotation of the sprite in degrees
	///\param angle The new angle to set the sprite to, in degrees
	void rotation(int angle);

	///\brief Getter: Returns the current scale in the x-axis, where 1 is no scaling.
	///\return the current amount the sprite is scaled by in the x-axis
	float scaleX();

	///\brief Getter: Returns the current scale in the y-axis, where 1 is no scaling.
	///\return the current amount the sprite is scaled by in the y-axis
	float scaleY();

	///\brief Setter: Sets the scale of the object in the x-axis
	///\param scale Sets the scale in the x-axis to this new scale value
	void scaleX(float scale);

	///\brief Setter: Sets the scale of the object in the y-axis
	///\param scale Sets the scale in the y-axis to this new scale value
	void scaleY(float scale);

	///\brief Setter: Scales the sprite by a factor in each axis
	///\param dx The factor to be scaled in the x-axis, where 1 is no change
	///\param dy The factor to be scaled in the y-axis, where 1 is no change
	void scale(float dx, float dy);

	///\brief Setter: Sets the scale of the sprite in absolute terms
	///\param xScale the new value of scale in the x-axis
	///\param yScale the new value of scale in the y-axis
	void scaleTo(float xScale, float yScale);

private:
	int x_;			///< The x co-ordinate of this sprite
	int y_;			///< The y co-ordinate of this sprite
	int rotation_;	///< Rotation in degrees from the positive x-axis
	float scaleX_;	///< Scale in the x-axis, where 1 is no scaling
	float scaleY_;	///< Scale in the y-axis, where 1 is no scaling
	int zPriority_;

	///\brief Helper function that wraps the rotation around 360 degrees
	///			Ensures that the rotation functions do not bring values that will ever be out of range 0->360.
	void wrapRotation();
};

#endif
