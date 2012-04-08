#include "../../include/ui.h"
#include "../../resource/tilemaps/tilemaps.h"

UI::UI()
{
	text_ = Tilemap(uiMap, MAP_WIDTH, MAP_HEIGHT);
	background_ = Tilemap(0, MAP_WIDTH, MAP_HEIGHT);
}
