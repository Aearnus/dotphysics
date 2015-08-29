#include "Element.h"
#include "ElementTypes.h"
#include "Constants.h"
#include <vector>

Element::Element(float xPos, float yPos, types t) {
    x = xPos;
    y = yPos;
    type = t;
}

void Element::tick(std::vector<Element> otherPixels) {
    for (auto e : otherPixels) { //for every pixel
        if (&e != this) { //that isn't the current one
            if ((x - e.x < 1.01) || (x > 5)) { //check if there's another pixel below or you're on the ground
                xVel = 0;
            } else {
                xVel += GRAVITY;
            }
            x += xVel;
        }
    }
}
    
