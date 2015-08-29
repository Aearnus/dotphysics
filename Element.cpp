#include "Element.h"
#include "ElementTypes.h"
#include <vector>

Element::Element(float xPos, float yPos, types t) {
    x = xPos;
    y = yPos;
    type = t;
}

void Element::tick(std::vector<Element> otherPixels) {
    for (auto e : world.pixels) { //for every pixel
        if (e != this) { //that isn't the current one
            if ((e.x - this.x < 1.01) || (this.x - HEIGHT < 5)) { //check if there's another pixel below or you're on the ground
                xVel = 0;
            } else {
                xVel += GRAVITY;
            }
            x += xVel;
        }
    }
}
    
