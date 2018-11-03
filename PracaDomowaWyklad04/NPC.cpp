#include "NPC.h"

NPC::NPC(sf::Vector2u startAtPosition, sf::Color color, float speed) {
	texture.loadFromFile("images/texture.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2));
	sprite.setPosition(static_cast<sf::Vector2f>(startAtPosition));
	sprite.setColor(color);
	this->speed = speed;
	movement = sf::Vector2f(speed*0.0003, speed*0.0003);
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

void NPC::collision(NPC& secondNPC) {
	if (sprite.getGlobalBounds().intersects(secondNPC.sprite.getGlobalBounds())) {
		movement.x = -movement.x;
		movement.y = -movement.y;
	}
}

void NPC::collision(Player& player) {
	if (sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
		movement.x = -movement.x;
		movement.y = -movement.y;
	}
}