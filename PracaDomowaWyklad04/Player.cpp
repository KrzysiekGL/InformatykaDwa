#include "Player.h"

Player::Player(sf::Vector2f startAtPosition, sf::Color color, float speed) {
	this->speed = speed;
	texture.loadFromFile("images/texture.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	sprite.setPosition(startAtPosition);
	sprite.setColor(color);
}

Player::~Player() {
}

void Player::updatePosition(float deltaTime) {
	movement = sf::Vector2f(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) movement.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) movement.y += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) movement.x += speed * deltaTime;
	sprite.move(movement);
}