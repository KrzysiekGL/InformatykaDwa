#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class NPC {
protected:
	sf::Texture texture;
	sf::Sprite sprite;

	float speed;
	float switchTime;
	sf::Vector2f movement;
	

public:
	NPC(sf::Vector2u startAtPosition, sf::Color color, float switchTime, float speed);
	~NPC();

	void drawNPC(sf::RenderWindow& window);
	void moveShapeInWindow(sf::RenderWindow& window);
};

