#include "World.h"
#include "ElementTypes.h"
#include "Element.h"

World::World() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			setPixel(x, y, Element());
		}
	}
}
