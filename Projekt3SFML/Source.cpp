#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Window - SFML");

	sf::Vector2u size = window.getSize();
	std::cout << "Width: " << size.x << '\n'
			<< "Height: " << size.y << '\n';

	sf::CircleShape triangle(80.f, 3);
	sf::CircleShape square(80.f, 4);
	sf::CircleShape octagon(80.f, 8);

	triangle.setPosition(0, 20);
	triangle.setFillColor(sf::Color::Red);

	square.setPosition(180, 20);
	square.setFillColor(sf::Color::Green);

	octagon.setPosition(360, 20);
	octagon.setFillColor(sf::Color::Blue);

	window.clear();

	window.draw(triangle);
	window.draw(square);
	window.draw(octagon);

	window.display();

	getchar();

	window.clear();

	sf::ConvexShape windShield;
	windShield.setFillColor(sf::Color::Yellow);
	windShield.setPointCount(3);
	windShield.setPoint(0, sf::Vector2f(0.f, 0.f));
	windShield.setPoint(1, sf::Vector2f(0.f, 40.f));
	windShield.setPoint(2, sf::Vector2f(40.f, 40.f));
	windShield.setPosition(200.f, 200.f);

	sf::RectangleShape cabin;
	cabin.setFillColor(sf::Color::Blue);
	cabin.setSize(sf::Vector2f(80, 40));
	cabin.setPosition(120.f, 200.f);

	sf::RectangleShape bottom;
	bottom.setFillColor(sf::Color::Blue);
	bottom.setSize(sf::Vector2f(150.f, 40.f));
	bottom.setPosition(100.f, 240.f);

	sf::CircleShape wheel(20.f);
	wheel.setFillColor(sf::Color::Red);

	sf::CircleShape backWheel = wheel;
	sf::CircleShape frontWheel = wheel;

	backWheel.setPosition(110.f, 260.f);
	frontWheel.setPosition(210.f, 260.f);

	sf::CircleShape head(8);
	head.setFillColor(sf::Color::Green);
	head.setPosition(180.f, 210.f);

	sf::RectangleShape torso(sf::Vector2f(10.f, 20.f));
	torso.setFillColor(sf::Color::Green);
	torso.setPosition(183.f, 225.f);

	window.draw(windShield);
	window.draw(cabin);
	window.draw(bottom);
	window.draw(backWheel);
	window.draw(frontWheel);
	window.draw(head);
	window.draw(torso);

	window.display();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}
	}

	return 0;
}