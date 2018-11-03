#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"

class NPC {
protected:
	sf::Texture texture;
	sf::Sprite sprite;

	float speed;
	sf::Vector2f movement;
	
public:
	NPC() {}
	NPC(sf::Vector2u startAtPosition, sf::Color color, float speed);
	~NPC();

	void drawNPC(sf::RenderWindow& window);
	void moveShapeInWindow(sf::RenderWindow& window);

	void collision(NPC& secondNPC);
	void collision(Player& player);
};

