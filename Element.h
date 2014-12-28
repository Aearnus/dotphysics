#pragma once
#include "ElementTypes.h"
class Element
{
public:
	Element(float xPos, float yPos, types t)
	{
		x = xPos;
		y = yPos;
		type = t;
	}

	float x;
	float y;
	float xVel;
	float yVel;
	types type;

private:
};