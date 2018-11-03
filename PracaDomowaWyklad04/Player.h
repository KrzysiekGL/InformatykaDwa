#pragma once
#include <SFML/Graphics.hpp>

class Player {
protected:
	sf::Texture texture;
	sf::Sprite sprite;

	float speed;
	sf::Vector2f movement;
public:
	Player(sf::Vector2f, sf::Color, float);
	~Player();

	void updatePosition(float deltaTime);

	void drawPlayer(sf::RenderWindow& window) { window.draw(sprite); }

	sf::Sprite getSprite() { return sprite; }
};

