#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>

struct ball {
	sf::Sprite sprite;
	sf::Vector2f v;
};

int main()
{
	Game game(sf::Vector2u(800, 600));
	game.start_game();
}

