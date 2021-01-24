#pragma once
#include "Map.h"

class Game {
private:
	sf::RenderWindow window;
	sf::Event event;
	Map map;
public:
	Game(sf::Vector2u w_size);
	void start_level(int level);
	void start_game();
};
