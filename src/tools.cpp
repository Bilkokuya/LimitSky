#include "../include/tools.h"
#include "../include/world.h"

Tool::Tool(){}
Tool::Tool(World* world){world_ = world;}

ToolHoe::ToolHoe(World* world):Tool(world){}
ToolWateringCan::ToolWateringCan(World* world):Tool(world){}
ToolSeeds::ToolSeeds(World* world):Tool(world){}
ToolScythe::ToolScythe(World* world):Tool(world){}

//	TOOL HOE
void ToolHoe::useTool(int x, int y, int width, int height)
{
	world_->tillSoil(x,y);
}

void ToolHoe::interact(int x, int y)
{
}


// TOOL WATERING CAN
void ToolWateringCan::useTool(int x, int y, int width, int height)
{
	world_->waterCrops(x,y);
}

void ToolWateringCan::interact(int x, int y)
{
}


// TOOL SEEDS
void ToolSeeds::useTool(int x, int y, int width, int height)
{
	world_->plantSeeds(x,y);
}

void ToolSeeds::interact(int x, int y)
{
}


//	TOOL SCYTHE
void ToolScythe::useTool(int x, int y, int width, int height)
{
	world_->harvestCrops(x,y);
}

void ToolScythe::interact(int x, int y)
{
}


