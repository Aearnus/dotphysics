#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "World.cpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), ".physics", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    bool running = true;
    while (running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                running = false;
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }
    return 0;
}