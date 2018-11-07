#include "Pokeball.h"

Pokeball::Pokeball(sf::Vector2f position, sf::RenderWindow& inWindow) {
	this->position = position;

	texture.loadFromFile("images/pokeball.png");

	sprite.setTexture(texture);
	sprite.setPosition(this->position);

	borders = inWindow.getSize();
}

void Pokeball::animation() {
	collision();
	move();
}

void Pokeball::move() {
	sprite.move(movement);
	position = sprite.getPosition();
}

void Pokeball::collision() {
	if (position.x <= 0) movement.x = -movement.x;
	if (position.x >= (borders.x - sprite.getLocalBounds().width)) movement.x = -movement.x;
	if (position.y <= 0) movement.y = -movement.y;
	if (position.y >= (borders.y - sprite.getLocalBounds().height)) movement.y = -movement.y;
}

void Pokeball::changeVelocity() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.x += 0.1f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.x -= 0.1f;
}

void Pokeball::draw(sf::RenderWindow& inWindow) {
	inWindow.draw(sprite);
}