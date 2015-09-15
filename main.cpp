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
            //if the mouse is in the window
            if (mousePos.x < WIDTH && mousePos.x > 0 && mousePos.y < HEIGHT && mousePos.y > 0) { 
                bool positionTaken = false;
                if (world.pixels[mousePos.y][mousePos.x] != nullptr) {
                    positionTaken = true;
                }
                if (!positionTaken) {
                    printf("putting element at X: %i, Y: %i\n", mousePos.x, mousePos.y);
                    world.placePixel((mousePos.x), (mousePos.y), new Element(DIRT));
                }
            }
        }

        //render/update loop
        window.clear(sf::Color::Black);
        for(size_t pixelY = 0; pixelY < HEIGHT; ++pixelY) {
            for(size_t pixelX = 0; pixelX < WIDTH; ++pixelX) {
                if (world.pixels[pixelY][pixelX] != nullptr) {
                    //Element* currentPixel = world.pixels[pixelY][pixelX];
                    //updating
                    //currentPixel->tick(world.pixels);
                
                    //rendering
                    sf::RectangleShape pix(sf::Vector2f(1,1));
                    pix.setPosition(pixelX, pixelY);
                    //pix.setFillColor(typeColors[currentPixel->type]);
                    pix.setFillColor(sf::Color(200, 150, 0));
                    window.draw(pix);
                }
            }
        }
        window.display();
    }
    return 0;
}
