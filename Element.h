#pragma once
#include "ElementTypes.h"
#include <vector>

class Element {
public:
    Element(types t);
    //void tick(Element* otherPixels[]);
	double xVel;
	double yVel;
	types type;

private:
};
