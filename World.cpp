#include "World.h"
#include "ElementTypes.h"
#include "Element.h"
#include "Constants.h"
#include <algorithm>

World::World() {
    //std::fill_n(pixels, WORLD_SIZE, nullptr);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[y][x] = nullptr;
        }
    }   
}

int World::placePixel(int x, int y, Element* pixel) {
    /*
    for (int worldIndex = 0; worldIndex < WORLD_SIZE; ++worldIndex) { //iterate through the world
        if (pixels[worldIndex] == nullptr) { //and replace the first null value
            pixels[worldIndex] = pixel;
            return 0;
        }
    }
    exit(-1); //if there's no more room, crash of course
    return -1;
    */
    pixels[y][x] = pixel;
    return 0;
}
