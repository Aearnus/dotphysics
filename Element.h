#pragma once
#include "ElementTypes.h"
#include <vector>

class Element {
public:
    Element(float xPos, float yPos, types t);
    void tick(Element* otherPixels[]);
	double x;
	double y;
	double xVel;
	double yVel;
	types type;

private:
};
