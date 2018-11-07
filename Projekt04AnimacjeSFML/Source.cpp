#include <iostream>

#include <SFML/Graphics.hpp>

#include "Pokeball.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Projekt04Animacje");
	window.setFramerateLimit(60);
	sf::Clock clock;
	float deltaTime;
	sf::Event event;

	Pokeball pokeball(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), window);

	while (window.isOpen()) {
		deltaTime = clock.restart().asMicroseconds();

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}

		pokeball.changeVelocity();
		if (deltaTime >= 50) pokeball.animation();

		window.clear(sf::Color(127, 127, 127, 255));

		pokeball.draw(window);

		window.display();
	}
}