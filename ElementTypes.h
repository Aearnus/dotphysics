#pragma once
#include <SFML/Graphics.hpp>

enum types {
	DIRT,
	DUST,
	WALL
};

sf::Color typeColors[] = {sf::Color(200, 150, 0),
						  sf::Color(255, 170, 10),
						  sf::Color(230, 30, 30)};