//Extension of the Tile class for GBA specifics

#ifdef CC_GBA

public:
	Tile(const unsigned char* tiledata);

	const unsigned char* tiledata_;
	int charblockIndex[5]; // Index that this tile has been loaded into for each charblock it could be in (charblock is the index).

private:

#endif