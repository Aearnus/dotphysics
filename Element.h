#pragma once
#include "ElementTypes.h"
class Element {
public:
	Element(float xPos, float yPos, types t)
	{
		x = xPos;
		y = yPos;
		type = t;
	}

	double x;
	double y;
	double xVel;
	double yVel;
	types type;

private:
};
