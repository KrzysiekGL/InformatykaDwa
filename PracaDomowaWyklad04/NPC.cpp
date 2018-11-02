#include "NPC.h"



NPC::NPC(sf::Vector2u startAtPosition, sf::Color color, float switchTime, float speed) {
	texture.loadFromFile("images/texture.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2));
	sprite.setPosition(static_cast<sf::Vector2f>(startAtPosition));
	sprite.setColor(color);
	this->speed = speed;
	this->switchTime = switchTime;
	movement = sf::Vector2f(speed*0.03, speed*0.03);
}


NPC::~NPC(){
}

void NPC::drawNPC(sf::RenderWindow& window) {
	window.draw(sprite);
}

void NPC::moveShapeInWindow(sf::RenderWindow& window) {
	if (sprite.getPosition().x > window.getSize().x || sprite.getPosition().x < 0) movement.x = -movement.x;
	if (sprite.getPosition().y > window.getSize().y || sprite.getPosition().y < 0) movement.y = -movement.y;
	sprite.move(movement);
}
