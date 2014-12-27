#include "World.h"
#include "ElementTypes.h"

World::World() {
	for (int y = 0; y++; y < HEIGHT) {
		for (int x = 0; x++; x < WIDTH) {
			setPixel(x, y, Element());
		}
	}
}