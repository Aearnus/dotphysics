#include "Element.h"
#include "ElementTypes.h"
#include "Constants.h"
#include <vector>
#include <cmath>

Element::Element(float xPos, float yPos, types t) {
    x = xPos;
    y = yPos;
    type = t;
}

void Element::tick(std::vector<Element> otherPixels) {
    int willApplyGravity = 1;
    for (auto e : otherPixels) { //for every pixel
        if (&e != this) { //that isn't the current one
            if ((y - e.y < 1.01) || (y > 5) || floor(x) - floor(e.x) == 0){ //check if there's another pixel below or you're on the ground
                willApplyGravity = 0;
            }
        }
    }
    if (willApplyGravity) {
        this->yVel += GRAVITY;
    } else {
        this->yVel = 0;
    }
    this->y += yVel;
}
    
