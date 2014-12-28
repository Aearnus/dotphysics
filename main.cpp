#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Constants.h"
#include "World.h"
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), ".physics", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    bool running = true;
    World world = World();
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (mousePos.x >= 0 && mousePos.x <= WIDTH && mousePos.y >= 0 && mousePos.y <= HEIGHT) {
                printf("PUTTING ELEMENT AT X: %i, Y: %i\n", mousePos.x, mousePos.y);
                world.setPixel(mousePos.x, mousePos.y, Element(DIRT));
            }
        }

        window.clear(sf::Color::Black);
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) { 
                switch (world.getPixel(x, y).getType()) {
                    case AIR:
                    break;
                    case DIRT: 
                    sf::RectangleShape pix(sf::Vector2f(1,1));
                    pix.setPosition(x, y);
                    pix.setFillColor(sf::Color(255, 150, 0));
                    window.draw(pix);
                    break;
                }
            }
        }
        window.display();
    }
    return 0;
}