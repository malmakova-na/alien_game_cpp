#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

std::string moves = "lrud";

Game::Game(sf::Vector2u w_size) {
	window.create(sf::VideoMode(600,600), "My game");
	window.setSize(w_size);
	window.setTitle("My Game");
}

int Game::start_level(int level) {
	bool self_flag = 0;
	int steps = 0;
	std::string path = "levels/" + std::to_string(level) + ".txt";
	map = Map(path);
	window.clear(sf::Color::White);
	map.draw_map(window);
	window.display();
	while (!map.is_complete()) {
		if (self_flag) {
			int prev_steps = steps;
			while (steps == prev_steps) {
				char move = moves[std::rand() % 4];
				steps += map.step(move);
			}
			window.clear(sf::Color::White);
			map.draw_map(window);
			window.display();
			usleep(300000);
		}
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space) {
					self_flag = !self_flag;
				}
				if (event.key.code == sf::Keyboard::R) {
					return 1;
				}
				if(!self_flag) {
					if (event.key.code == sf::Keyboard::Left) {
						steps += map.step('l');
						window.clear(sf::Color::White);
						map.draw_map(window);
						window.display();

					}
					else if (event.key.code == sf::Keyboard::Right) {
						steps += map.step('r');
						window.clear(sf::Color::White);
						map.draw_map(window);
						window.display();
					}
					else if (event.key.code == sf::Keyboard::Up) {
						steps += map.step('u');
						window.clear(sf::Color::White);
						map.draw_map(window);
						window.display();
					}
					else if (event.key.code == sf::Keyboard::Down) {
						steps += map.step('d');
						window.clear(sf::Color::White);
						map.draw_map(window);
						window.display();
					}
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			steps += map.step('l');
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			steps += map.step('r');
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			steps += map.step('u');
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			steps += map.step('d');
		window.clear(sf::Color::White);
		map.draw_map(window);
		window.display();
	}
	return 0;
}

void Game::start_game() {
	int n = 2;
	int i = 0;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		std::cout << "start level " << i + 1 << "\n";
		int r = start_level(i + 1);
		if (r == 0){
			i = (i + 1) % n;
		}
	}
}