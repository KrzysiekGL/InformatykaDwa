#pragma once
#include <SFML/Graphics.hpp>

class Pokeball{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f movement = sf::Vector2f(1.f,1.f);
	sf::Vector2u borders;
public:
	Pokeball() {};
	~Pokeball() {};

	Pokeball(sf::Vector2f position, sf::RenderWindow& inWindow);

	void animation();
	void move();
	void changeVelocity();
	void collision();
	void draw(sf::RenderWindow& inWindow);
};