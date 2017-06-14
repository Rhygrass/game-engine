#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <SFML\Graphics.hpp>
#include "animation.h"

class Player
{
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	float finPos;
	bool faceRight;
	bool isMoving;
	enum direction { up, down, left, right, still } movement;
	sf::Vector2f currentPosition;
	sf::Vector2f targetPosition;
	
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	void move(float deltaTime);

	sf::Vector2f getPosition();
};

#endif