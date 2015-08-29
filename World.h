#pragma once
#include "Constants.h"
#include "Element.h"
#include <vector>

class World {
public:
	World();
    int placePixel(Pixel* pixel);
	Pixel* world[WORLD_SIZE] pixels;
};
