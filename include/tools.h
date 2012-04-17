#ifndef LS_TOOL
#define LS_TOOL

#include "world.h"

//	Tool Base class
//	Making use of the Strategy Pattern
class Tool
{
public:
	Tool();	
	Tool(World* world);
	virtual void useTool(int x, int y, int width = 1, int height = 1) = 0;
	virtual void interact(int x, int y) = 0;

protected:
	int durability_;	//	When 0, the tool needs repaired
	int level_;			//	Level from 1 to 5; increasing the maximum width and height
	World* world_;
};


//	Watering can for watering dirt and soil to keep crops alive
class ToolWateringCan: public Tool
{
public:
	ToolWateringCan(World* world);
	void useTool(int x, int y, int width = 1, int height = 1);
	void interact(int x, int y);

private:
	int waterCapacity_;
	int waterFill_;
};


//	A Hoe for tilling dirt into soil, that can be planted on
class ToolHoe: public Tool
{
public:
	ToolHoe(World* world);
	void useTool(int x, int y, int width = 1, int height = 1);
	void interact(int x, int y);
};


//	Seeds for planting new crops on soil
class ToolSeeds: public Tool
{
public:
	ToolSeeds(World* world);
	void useTool(int x, int y, int width = 1, int height = 1);
	void interact(int x, int y);
};


//	Sycthe for harvesting crops that have already been planted
class ToolScythe: public Tool
{
public:
	ToolScythe(World* world);
	void useTool(int x, int y, int width = 1, int height = 1);
	void interact(int x, int y);
};

#endif
