#include "player.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
		animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(32.0f, 32.0f));
	body.setPosition(512.0f, 512.0f);
	//body.setOrigin(body.getSize() / 2.0f);
	body.setOrigin(0.0f, 0.0f);
	body.setTexture(texture);
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	if (currentPosition == targetPosition)
	{
		movement = still;
		row = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			isMoving = true;
			movement = up;
			currentPosition = body.getPosition();
			targetPosition = sf::Vector2f(currentPosition.x, currentPosition.y - 32.0f);
			row = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			isMoving = true;
			movement = down;
			currentPosition = body.getPosition();
			targetPosition = sf::Vector2f(currentPosition.x, currentPosition.y + 32.0f);
			row = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			isMoving = true;
			movement = left;
			currentPosition = body.getPosition();
			targetPosition = sf::Vector2f(currentPosition.x - 32.0f, currentPosition.y);
			row = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			isMoving = true;
			movement = right;
			currentPosition = body.getPosition();
			targetPosition = sf::Vector2f(currentPosition.x + 32.0f, currentPosition.y);
			row = 1;
		}
	}
	animation.update(row, deltaTime, movement);
	body.setTextureRect(animation.uvRect);
	move(deltaTime);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::move(float deltaTime)
{
	if (isMoving)
	{
		switch (movement) {
		case up:
			if (currentPosition.y < targetPosition.y)
			{
				isMoving = false;
				targetPosition = currentPosition;
			}
			else
			{
				body.move(sf::Vector2f(0.0f, -speed * deltaTime));
				currentPosition = body.getPosition();
			}
			break;
		case down:
			if (currentPosition.y > targetPosition.y)
			{
				isMoving = false;
				targetPosition = currentPosition;
			}
			else
			{
				body.move(sf::Vector2f(0.0f, speed * deltaTime));
				currentPosition = body.getPosition();
			}
			break;
		case left:
			if (currentPosition.x < targetPosition.x)
			{
				isMoving = false;
				targetPosition = currentPosition;
			}
			else
			{
				body.move(sf::Vector2f(-speed * deltaTime, 0.0f));
				currentPosition = body.getPosition();
			}
			break;
		case right:
			if (currentPosition.x > targetPosition.x)
			{
				isMoving = false;
				targetPosition = currentPosition;
			}
			else
			{
				body.move(sf::Vector2f(speed * deltaTime, 0.0f));
				currentPosition = body.getPosition();
			}
			break;
		}
	}
}

sf::Vector2f Player::getPosition()
{
	return body.getPosition();
}