#pragma once
#include <vector>
#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <string>


class Map{

private:
	std::vector<std::vector<Cell>> map;
	std::vector<sf::Vector2i> xs;
	sf::Vector2i dude;

public:
	Map() {};
	Map(std::string path);
	void print_map();
	void draw_map(sf::RenderWindow& window);
	int step(char c);// 'l', 'r', 'u', 'd'
	bool is_complete();
};