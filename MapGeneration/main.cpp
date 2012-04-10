
#include <iostream>
#include <fstream>

#define MAPWIDTH 500
#define MAPHEIGHT 32 // DO NOT CHANGE THIS - MAPS SHOULD BE HIGHLY LINEAR
#define TERRAIN_TYPES 6

int mapdata[MAPWIDTH*MAPHEIGHT] = {0};

void generateMap()
{
	for (int i = 0; i < MAPHEIGHT; ++i){
		for (int j = 0; j < MAPWIDTH; ++j){
			mapdata[(i*MAPWIDTH) + j] = (rand()%TERRAIN_TYPES);
		}
	}
}

void smoothMap()
{
	for (int i = 1; i < MAPHEIGHT; ++i){
		for (int j = 1; j < MAPWIDTH; ++j){
			if ( (rand()%10) < 7){
				unsigned char a = 0;
				a += mapdata[(i*MAPWIDTH) + j-1];
				a += mapdata[(i*MAPWIDTH) + j];
				a += mapdata[((i-1)*MAPWIDTH) + j-1];
				a += mapdata[((i-1)*MAPWIDTH) + j];
				a = a/4;
				mapdata[(i*MAPWIDTH) + j] = a;
			}
		}
	}
}

void smallToBig()
{
	for (int i = 0; i < MAPHEIGHT/2; ++i){
		for (int j = 0; j < MAPWIDTH/2; ++j){
			int a = mapdata[(2*i)*MAPWIDTH + (2*j)];
			a *= 2;
			mapdata[(2*i)*MAPWIDTH + (2*j)] = a;
			mapdata[(2*i)*MAPWIDTH + (2*j)+1] = a+1;
			mapdata[((2*i)+1)*MAPWIDTH + (2*j)] = a+16;
			mapdata[((2*i)+1)*MAPWIDTH + (2*j)+1] = a+16+1;
		}
	}
}

void main()
{
	generateMap();
	smoothMap();
	smoothMap();
	smoothMap();
	smoothMap();
	smoothMap();
	smallToBig();

	std::ofstream file;
	file.open("C:/Projects/LimitSky/resource/maps/map.h");
	file << "// Generated by Gordon Mckendrick's Map Generator" << std::endl;

	file << "#define MAPWIDTH " << MAPWIDTH << std::endl;
	file << "#define MAPHEIGHT " << MAPHEIGHT << std::endl;
	file << "const unsigned char map[MAPWIDTH * MAPHEIGHT] = {" << std::endl;

	for (int i = 0; i < MAPHEIGHT; ++i){
		file << "\t";

		for (int j = 0; j < MAPWIDTH; ++j){
			file << mapdata[(i*MAPWIDTH) + j] << ",";
		}
		std::cout << std::endl;
		file << std::endl;
	}

	file << "};" << std::endl;
	file.close();
}