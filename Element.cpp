#include "Element.h"
#include "ElementTypes.h"
#include "Constants.h"
#include <vector>
#include <cmath>

Element::Element(types t) {
    type = t;
}
/*
void Element::tick(Element* otherPixels[]) {
    int willApplyGravity = 1;
    for (int pixelIndex = 0; pixelIndex < WORLD_SIZE; ++pixelIndex) { //for every pixel
        Element* currentPixel = otherPixels[pixelIndex];
        if (currentPixel != this && currentPixel != nullptr) { //that isn't the current one or null
            if (y > (HEIGHT - 10)) {
                willApplyGravity = 0;
                break;
            }
        }
    }
    if (willApplyGravity) {
        yVel += GRAVITY;
    } else {
        yVel = 0;
    }
    y += yVel;
}
    
*/
