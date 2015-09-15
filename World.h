#pragma once
#include "Constants.h"
#include "Element.h"
#include <vector>

class World {
public:
	World();
    int placePixel(int x, int y, Element* pixel);
	Element* pixels[HEIGHT][WIDTH];
};
