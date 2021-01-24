#include "pch.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Windows.h"
#include <cmath>

struct ball {
	sf::Sprite sprite;
	sf::Vector2f v;
};

int main()
{
	Game game(sf::Vector2u(800, 600));
	game.start_game();
	/*Map map("levels/1.txt");
	std::string r= "dlu";
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	int i = -1;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (i < 3 && i >= 0) {
			std::cout << "\n" << r[i] << "\n\n";
			map.step(r[i]);
		}
		map.print_map();
		window.clear(sf::Color::White);
		map.draw_map(window);
		window.display();
		Sleep(1000);
		i += 1;
	}*/

/*
	sf::Texture texture;
	texture.loadFromFile("icons/cap.png");
	sf::Sprite circle(texture);
	circle.setScale(0.5, 0.5);
	circle.setPosition(10, 10);
	int i=0;
	sf::Clock clock;
	std::vector<sf::Sprite> balls;


	while (window1.isOpen() || window2.isOpen()) {
		sf::Event event1;
		sf::Event event2;
		while (window1.pollEvent(event1)) {
			if (event1.type == sf::Event::Closed)
				window1.close();

			if (event1.type == sf::Event::TextEntered) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					if (!s_in1.isEmpty()) {
						s_in1.erase(s_in1.getSize() - 1);
						txt1.setString(s_in1);
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) ){
					s_in1 += "\n";
					txt1.setString(s_in1);
				}
				else {
					s_in1 += event1.text.unicode;
					txt1.setString(s_in1);
				}
			}
		}

		while (window2.pollEvent(event2)) {
			if (event2.type == sf::Event::Closed)
				window2.close();

			if (event2.type == sf::Event::TextEntered) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					if (!s_in2.isEmpty()) {
						s_in2.erase(s_in2.getSize() - 1);
						txt2.setString(s_in2);
					}

				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
					s_in2 += "\n";
	
					txt2.setString(s_in2);
					
				}
				else {
					
					s_in2 += event2.text.unicode;
					s_in1 += event2.text.unicode;
					txt1.setString(s_in1);
				}
			}
		}

		
		
		sf::Time time = clock.getElapsedTime();
		sf::Vector2f position = circle.getPosition();
		sf::Vector2f center = position + sf::Vector2f(32, 32);
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window1);
		sf::Vector2f d = sf::Vector2f(mouse_position.x, mouse_position.y) - position;
		float alfa = std::atan2f(d.x, d.y);
		circle.setRotation(180 - alfa*180/3.1415);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position.x + 64 <= 800) {
			circle.move(0.1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& position.y + 64<= 600) {
			circle.move(0, 0.1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& position.x>= 0 ) {
			circle.move(-0.1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& position.y>= 0) {
			circle.move(0, -0.1);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			sf::Texture b_text;
			b_text.loadFromFile("icons/google.png");
			ball b;
			b.sprite = sf::Sprite(b_text);
			b.sprite.setScale(0.2, 0.2);
			b.sprite.setPosition(position);
			float v_len = 0.1;

		}
		window1.clear(sf::Color::Yellow);
	//	window1.draw(circle);
		window1.draw(txt1);
		window1.draw(txt2);
		window1.draw(txt_title1);
	//	window1.draw(txt_title2);
		window1.display();

		window2.clear(sf::Color::Magenta);
		//	window1.draw(circle);
		window2.draw(txt1);
		window2.draw(txt2);
	//	window2.draw(txt_title1);
		window2.draw(txt_title2);
		window2.display();
	}*/
}

