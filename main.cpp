#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Constants.h"
#include "World.h"
#include <string>
#include <vector>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), ".physics", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    bool running = true;
    World world = World();
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }

        //placing pixels
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (mousePos.x >= 0 && mousePos.x <= WIDTH && mousePos.y >= 0 && mousePos.y <= HEIGHT) {
                bool positionTaken = false;
                for(int pixelY = 0; pixelY < HEIGHT; ++pixelY) {
                    for(int pixelX = 0; pixelX < WIDTH; ++pixelX) {
                        Element* e = world.pixels[pixelY][pixelX];
                        if (e != nullptr) {
                            if (pixelX == mousePos.x || pixelY == mousePos.y) { //if there's not a pixel under your cursor
                                positionTaken = true;
                            }
                        }
                    }
                }
                if (!positionTaken) {
                    printf("putting element at X: %i, Y: %i\n", mousePos.x, mousePos.y);
                    Element* tempElement = new Element(DIRT);
                    world.placePixel((int)floor(mousePos.x), (int)floor(mousePos.y), tempElement);
                }
            }
        }

        //render/update loop
        window.clear(sf::Color::Black);
        for(size_t pixelY = 0; pixelY < HEIGHT; ++pixelY) {
            for(size_t pixelX = 0; pixelX < WIDTH; ++pixelX) {
                if (world.pixels[pixelY][pixelX] != nullptr) {
                    Element* currentPixel = world.pixels[pixelY][pixelX];
                    //updating
                    //currentPixel->tick(world.pixels);
                
                    //rendering
                    sf::RectangleShape pix(sf::Vector2f(1,1));
                    pix.setPosition(pixelX, pixelY);
                    pix.setFillColor(typeColors[currentPixel->type]);
                    window.draw(pix);
                }
            }
        }
        window.display();
    }
    return 0;
}
