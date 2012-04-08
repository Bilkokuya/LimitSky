#ifndef LS_TILEMAP
#define LS_TILEMAP

#include <list>

class Tilemap
{
public:
	Tilemap();
	Tilemap(const unsigned char* tiledata, int width, int height);

	unsigned char getTileAt(int x, int y);

private:
	int width_;
	int height_;
	const unsigned char* tiledata_;
	std::list<unsigned char> tilechanges_;

};
#endif