#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Constants.h"
#include "World.h"
#include <string>
#include <vector>

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
                world.pixels.push_back(Element((float)mousePos.x, (float)mousePos.y, DIRT));
            }
        }

        window.clear(sf::Color::Black);
        for(std::vector<Element>::iterator it = world.pixels.begin(); it != world.pixels.end(); ++it) {
            switch ((*it).type) {
                case DIRT: 
                sf::RectangleShape pix(sf::Vector2f(1,1));
                pix.setPosition((int)(*it).x, (int)(*it).y);
                pix.setFillColor(sf::Color(255, 150, 0));
                window.draw(pix);
                break;
            }
        }
        window.display();
    }
    return 0;
}