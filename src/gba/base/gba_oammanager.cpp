#include "../../../include/base/oammanager.h"
#include "../../../include/base/sprite.h"
#include "../../../lib/gba/gba.h"

//	Default Constructor
OAMManager::OAMManager()
{
}

//	Draws a given sprite into the OAM
void OAMManager::drawSprite(int index, Sprite* sprite)
{
	//!!! REPLACE VALUES WITH VALUES FROM sprite*
	SetObject(index,
		ATTR0_SHAPE(1) | ATTR0_8BPP | ATTR0_REG,
		ATTR1_SIZE(1),
		ATTR2_PRIO(sprite->zPriority())
		);
}