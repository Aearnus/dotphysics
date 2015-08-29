#pragma once
#include "Constants.h"
#include "Element.h"
#include <vector>

class World {
public:
	World();
    int placePixel(Element* pixel);
	Element* pixels[WORLD_SIZE];
};
