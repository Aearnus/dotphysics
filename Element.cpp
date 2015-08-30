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

void Element::tick(Element* otherPixels[]) {
    int willApplyGravity = 1;
    for (int pixelIndex = 0; pixelIndex < WORLD_SIZE; ++pixelIndex) { //for every pixel
        Element* currentPixel = otherPixels[pixelIndex];
        if (currentPixel != this && currentPixel != nullptr) { //that isn't the current one or null
            if ((y - currentPixel->y < 1.01) || (y > 5) || floor(x) - floor(currentPixel->x) == 0){ //check if there's another pixel below or you're on the ground
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
    
