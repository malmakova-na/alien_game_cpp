#include "pch.h"
#include "Game.h"
#include <iostream>
#include "Windows.h"
#include <cstdlib>

std::string moves = "lrud";

Game::Game(sf::Vector2u w_size) {
	window.create(sf::VideoMode(600,600), "My game");
	window.setSize(w_size);
	window.setTitle("My Game");
}

void Game::start_level(int level) {
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
			Sleep(300);
		}
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space)
					self_flag = !self_flag;
				
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
}

void Game::start_game() {
	int n = 2;
	int i = 0;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			std::cout << "start!\n";
			start_level(i+1);
			i = (i + 1) % n;
		}
	}
}