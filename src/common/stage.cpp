#include "../../../include/common/stage.h"

//	Default Constructor
Stage::Stage()
{
	sprites = new Sprite*[128];
}

//	Default Destructor
Stage::~Stage()
{
	delete[] sprites;
}