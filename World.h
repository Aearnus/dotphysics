#pragma once
#include "Constants.h"
#include "Element.h"
class World 
{
public:
	World();

	Element getPixel(int x, int y) {
		return grid[y][x];
	}
	void setPixel(int x, int y, Element elem) {
		grid[y][x] = elem;
	}

private:
	Element grid[HEIGHT][WIDTH];
};