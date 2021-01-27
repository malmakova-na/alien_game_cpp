#include "Map.h"
#include <fstream>
#include <iostream>
#include <algorithm>

sf::Sprite get_sprite(std::string path, sf::Vector2f size) {
	sf::Texture texture;
	texture.loadFromFile(path);
	sf::Sprite sprite(texture);
	float scale_x = size.x / sprite.getGlobalBounds().height;
	float scale_y = size.y / sprite.getGlobalBounds().width;
	sprite.setScale(scale_x, scale_y);
	return sprite;
}

sf::Vector2f icon_size(64, 64);

Map::Map(std::string path) {
	std::ifstream in(path);
	if (in.is_open()) {
		int n, m;
		in >> n;
		in >> m;
		for (int i = 0; i < n; i++) {
			std::vector<Cell> t_cells;
			for (int j = 0; j < n; j++) {
				int t;
				in >> t;
				Cell t_cell(t);
				t_cells.push_back(t_cell);
			}
			map.push_back(t_cells);
		}
		int k;
		in >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			in >> x;
			in >> y;
			xs.push_back(sf::Vector2i(x, y));
		}
		int dude_x, dude_y;
		in >> dude_x;
		in >> dude_y;
		dude = sf::Vector2i(dude_x, dude_y);
	}
	in.close();
}

void Map::print_map() {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++)
			std::cout << map[i][j].get_type() << ' ';
		std::cout << std::endl;
	}
	for (int i = 0; i < xs.size(); i++)
		std::cout << xs[i].x << " " << xs[i].y << std::endl;
	std::cout << dude.x << " " << dude.y;
}

void Map::draw_map(sf::RenderWindow& window) {

	sf::Vector2f pos_back = sf::Vector2f(0, 0);
	int n = map.size();
	int m = map[0].size();
	sf::Texture texture_back;
	texture_back.loadFromFile("icons/sky.png");
	sf::Sprite sprite_back(texture_back);
	float scale_x =600 / sprite_back.getGlobalBounds().height;
	float scale_y = 600 / sprite_back.getGlobalBounds().width;
	sprite_back.setScale(scale_x, scale_y);
	sprite_back.setPosition(pos_back);
	window.draw(sprite_back);

	for (auto v : xs) {
		sf::Vector2f pos = sf::Vector2f(50 + icon_size.x*v.y, 50 + icon_size.y*v.x);
		sf::Texture texture_x;
		texture_x.loadFromFile("icons/hole.png");
		sf::Sprite sprite_x(texture_x);
		float scale_x = icon_size.x / sprite_x.getGlobalBounds().height;
		float scale_y = icon_size.y / sprite_x.getGlobalBounds().width;
		sprite_x.setScale(scale_x, scale_y);
		sprite_x.setPosition(pos);
		window.draw(sprite_x);
	}

	for(int i = 0; i < map.size(); i++)
		for (int j = 0; j < map[i].size(); j++) {
			sf::Vector2f pos = sf::Vector2f(50 + j * icon_size.x, 50 + i * icon_size.y);
			int type = map[i][j].get_type();
			if (type == 2) {
				if (std::find(xs.begin(), xs.end(), sf::Vector2i(i, j)) != xs.end()) {
					sf::Texture texture_map;
					texture_map.loadFromFile("icons/planet1.png");
					sf::Sprite sprite_map(texture_map);
					float scale_x = icon_size.x / sprite_map.getGlobalBounds().height;
					float scale_y = icon_size.y / sprite_map.getGlobalBounds().width;
					sprite_map.setScale(scale_x, scale_y);
					sprite_map.setPosition(pos);
					window.draw(sprite_map);
				}
				else {
					sf::Texture texture_map;
					texture_map.loadFromFile("icons/planet2.png");
					sf::Sprite sprite_map(texture_map);
					float scale_x = icon_size.x / sprite_map.getGlobalBounds().height;
					float scale_y = icon_size.y / sprite_map.getGlobalBounds().width;
					sprite_map.setScale(scale_x, scale_y);
					sprite_map.setPosition(pos);
					window.draw(sprite_map);
				}
			}
			else if (type == 0) {
				sf::Texture texture_map;
				texture_map.loadFromFile("icons/bl.png");
				sf::Sprite sprite_map(texture_map);
				float scale_x = icon_size.x / sprite_map.getGlobalBounds().height;
				float scale_y = icon_size.y / sprite_map.getGlobalBounds().width;
				sprite_map.setScale(scale_x, scale_y);
				sprite_map.setPosition(pos);
				window.draw(sprite_map);
			}
		}
	sf::Vector2f pos = sf::Vector2f(50 + 64 * dude.y, 50 + 64 * dude.x);
	sf::Texture texture_dude;
	texture_dude.loadFromFile("icons/UFOdude.png");
	sf::Sprite sprite_dude(texture_dude);
	scale_x = icon_size.x / sprite_dude.getGlobalBounds().height;
	scale_y = icon_size.y / sprite_dude.getGlobalBounds().width;
	sprite_dude.setScale(scale_x, scale_y);
	sprite_dude.setPosition(pos);
	window.draw(sprite_dude);
}

int Map::step(char c) {
	if (c == 'l') {
		if(map[dude.x][dude.y - 1].get_type() == 0)
			return 0;
		if (map[dude.x][dude.y - 1].get_type() == 1) {
			dude.y -= 1;
			return 1;
		}
		if (map[dude.x][dude.y - 1].get_type() == 2 && map[dude.x][dude.y - 2].get_type() == 1) {
			map[dude.x][dude.y - 1].change_type(1);
			map[dude.x][dude.y - 2].change_type(2);
			dude.y -= 1;
		}
	}
	if (c == 'r') {
		if (map[dude.x][dude.y + 1].get_type() == 0)
			return 0;
		if (map[dude.x][dude.y + 1].get_type() == 1) {
			dude.y += 1;
			return 1;
		}
		if (map[dude.x][dude.y + 1].get_type() == 2 && map[dude.x][dude.y + 2].get_type() == 1) {
			map[dude.x][dude.y + 1].change_type(1);
			map[dude.x][dude.y + 2].change_type(2);
			dude.y += 1;
		}
	}
	if (c == 'u') {
		if (map[dude.x - 1][dude.y].get_type() == 0)
			return 0;
		if (map[dude.x - 1][dude.y].get_type() == 1) {
			dude.x -= 1;
			return 1;
		}
		if (map[dude.x - 1][dude.y].get_type() == 2 && map[dude.x - 2][dude.y].get_type() == 1) {
			map[dude.x - 1][dude.y].change_type(1);
			map[dude.x - 2][dude.y].change_type(2);
			dude.x -= 1;
		}
	}
	if (c == 'd') {
		if (map[dude.x + 1][dude.y].get_type() == 0)
			return 0;
		if (map[dude.x + 1][dude.y].get_type() == 1) {
			dude.x += 1;
			return 1;
		}
		if (map[dude.x + 1][dude.y].get_type() == 2 && map[dude.x + 2][dude.y].get_type() == 1) {
			map[dude.x + 1][dude.y].change_type(1);
			map[dude.x + 2][dude.y].change_type(2);
			dude.x += 1;
		}
	}
	return 0;
}

bool Map::is_complete() {
	int count = 0;
	for (auto v : xs)
		if (map[v.x][v.y].get_type() == 2)
			count += 1;
	if (count == xs.size())
		return 1;
	else
		return 0;
}