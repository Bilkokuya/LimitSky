#ifndef LS_TOOL
#define LS_TOOL

#include "world.h"

//	Tool Base class
//	Making use of the Strategy Pattern
class Tool
{
public:
	Tool();	
	Tool(World* world, char* name, int length);
	virtual ~Tool();
	virtual void useTool(int x, int y, int width = 1, int height = 1) = 0;
	virtual void interact(int x, int y) = 0;

	char* name();
	int nameLength();

protected:
	char* name_;		//	Name of this tool
	int nameLength_;	//	Length of the name of the tool
	int durability_;	//	When 0, the tool needs repaired
	int level_;			//	Level from 1 to 5; increasing the maximum width and height
	World* world_;
};


//	Watering can for watering dirt and soil to keep crops alive
class ToolWateringCan: public Tool
{
public:
	ToolWateringCan(World* world);
	virtual ~ToolWateringCan();
	virtual void useTool(int x, int y, int width = 1, int height = 1);
	virtual void interact(int x, int y);

private:
	int waterCapacity_;
	int waterFill_;
};


//	A Hoe for tilling dirt into soil, that can be planted on
class ToolHoe: public Tool
{
public:
	ToolHoe(World* world);
	virtual ~ToolHoe();
	virtual void useTool(int x, int y, int width = 1, int height = 1);
	virtual void interact(int x, int y);
};


//	Seeds for planting new crops on soil
class ToolSeeds: public Tool
{
public:
	int* seeds_;

	ToolSeeds(World* world, int* seeds);
	virtual ~ToolSeeds();
	virtual void useTool(int x, int y, int width = 1, int height = 1);
	virtual void interact(int x, int y);
};


//	Sycthe for harvesting crops that have already been planted
class ToolScythe: public Tool
{
public:
	int* seeds_;

	ToolScythe(World* world, int* seeds);
	virtual ~ToolScythe();
	virtual void useTool(int x, int y, int width = 1, int height = 1);
	virtual void interact(int x, int y);
};

#endif
