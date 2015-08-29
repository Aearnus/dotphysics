#include "World.h"
#include "ElementTypes.h"
#include "Element.h"
#include "Constants.h"
#include <algorithm>

World::World() {
    std::fill_n(world, WORLD_SIZE, nullptr);
}

int World::placePixel(Pixel* pixel) {
    for (int worldIndex = 0; worldIndex < WORLD_SIZE; ++worldIndex) { //iterate through the world
        if (world[worldIndex] == nullptr) { //and replace the first null value
            world[worldIndex] = pixel;
        } else {
            exit(-1); //if there's no room, crash TODO FIX
        }
    }
}
