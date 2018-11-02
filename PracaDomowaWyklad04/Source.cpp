#include <SFML/Graphics.hpp>

#include <iostream>

#include "Menu.h"
#include "NPC.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML menu/movement/collision(?) demo");
	sf::Event event;
	sf::Clock clock;
	float deltaTime;

	bool isMenuLaunched = true;

	Menu menu(window.getSize());

	//Entities
	NPC prop1(sf::Vector2u(100,100), sf::Color::Green, 0, 0);
	NPC prop2(sf::Vector2u(200,300), sf::Color::Red, 0, 5);

	while (window.isOpen()){
		deltaTime = clock.restart().asSeconds();
		while (window.pollEvent(event)) {
			//Close
			if (event.type == sf::Event::Closed) window.close();

			//TEMP- Menu selection
			if (event.type == sf::Event::KeyPressed) {
				if (isMenuLaunched) {
					if (event.key.code == sf::Keyboard::Up) menu.moveSelection(true);
					if (event.key.code == sf::Keyboard::Down) menu.moveSelection(false);
				}
				if (!isMenuLaunched) {

				}

				if (isMenuLaunched) {
					if (event.key.code == sf::Keyboard::Enter) {
						switch (menu.getSelectedItem()){
						case 0:
							isMenuLaunched = false;
							break;

						case 1:
							isMenuLaunched = false;
							window.close();
							break;

						default:
							break;
						}
					}
				}
			}
		}

		//Clear && Draw && Display CDD
		if(isMenuLaunched) window.clear(sf::Color(127, 127, 127, 255));
		if (!isMenuLaunched) window.clear();

		if(isMenuLaunched) menu.draw(window);
		if (!isMenuLaunched) {
			prop1.drawNPC(window);
			prop2.drawNPC(window);
			prop2.moveShapeInWindow(window);
		}

		window.display();
	}
}