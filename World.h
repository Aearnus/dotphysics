#pragma once
#include "Constants.h"
#include "Element.h"
#include <vector>
class World {
public:
	World();
    void Tick();
	std::vector<Element> pixels;
};
