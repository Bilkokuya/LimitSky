#ifdef CC_WIN32

public:
	//	Rotation Accessors
	int	rotation();
	void rotate(int dw);
	void rotation(int angle);

	//	Scale Accessors
	float scaleX();
	float scaleY();
	void scaleX(float scale);
	void scaleY(float scale);
	void scale(float dx, float dy);
	void scaleTo(float xScale, float yScale);

private:
	int width_;
	int height_;
	int rotation_;	///< Rotation in degrees from the positive x-axis
	float scaleX_;	///< Scale in the x-axis, where 1 is no scaling
	float scaleY_;	///< Scale in the y-axis, where 1 is no scaling

	///\brief Helper function that wraps the rotation around 360 degrees
	///			Ensures that the rotation functions do not bring values that will ever be out of range 0->360.
	void wrapRotation();

#endif
