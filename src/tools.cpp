#include "../include/tools.h"
#include "../include/world.h"

Tool::Tool(){}
Tool::Tool(World* world, char* name, int length)
{
	world_ = world;
	name_ = name;
	nameLength_ = length;
}

char* Tool::name()
{
	return name_;
}

int Tool::nameLength()
{
	return nameLength_;
}


//	Constructors, simply calling the Tool() constructor
ToolHoe::ToolHoe(World* world)					:Tool(world, "Hoe", 3){}
ToolWateringCan::ToolWateringCan(World* world)	:Tool(world, "Water Can", 9){}
ToolSeeds::ToolSeeds(World* world, int* seeds)	:Tool(world, "Seeds", 5){ seeds_ = seeds;}
ToolScythe::ToolScythe(World* world, int* seeds):Tool(world, "Scythe", 6){seeds_ = seeds;}

//	Virtual deconstructors as these tools are instanced and deleted through pointer to Tool.
Tool::~Tool(){}
ToolHoe::~ToolHoe(){}
ToolWateringCan::~ToolWateringCan(){}
ToolSeeds::~ToolSeeds(){}
ToolScythe::~ToolScythe(){}


//	TOOL HOE (tills)
void ToolHoe::useTool(int x, int y, int width, int height)
{
	int block = 0;
	switch (world_->getTerrain(x,y)){
		case 2: block = 4; break; // dirt	-> soil
		case 3: block = 5; break; // wet dirt -> wet soil
		default: return;
	}
	world_->setTerrain(x, y, block);
}

void ToolHoe::interact(int x, int y)
{
}


// TOOL WATERING CAN (waters)
void ToolWateringCan::useTool(int x, int y, int width, int height)
{
	int block = 0;
	switch (world_->getTerrain(x,y)){
		case 2: block = 3; break; // dirt -> wet dirt
		case 4: block = 5; break; // soil -> wet soil
		default: return;
	}
	world_->setTerrain(x, y, block);
}

void ToolWateringCan::interact(int x, int y)
{
}


// TOOL SEEDS (plants)
void ToolSeeds::useTool(int x, int y, int width, int height)
{
	//	if the terrain is tilled, and there is no existing crop there - plant seeds
	if (((world_->getTerrain(x,y) == 4) || (world_->getTerrain(x,y) == 5))
		&& (world_->getObject(x,y) == 0)){
		world_->setObject(x, y, 8);
	}
}

void ToolSeeds::interact(int x, int y)
{
}


//	TOOL SCYTHE (harvests/ cuts grass)
void ToolScythe::useTool(int x, int y, int width, int height)
{
	if (world_->getTerrain(x,y) == 1) world_->setTerrain(x,y,2); // Cuts grass -> dirt
	world_->setObject(x, y, 0); // replace crop with blank
}

void ToolScythe::interact(int x, int y)
{
}


