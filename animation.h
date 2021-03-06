#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include <SFML\Graphics.hpp>

class Animation
{
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
public:
	sf::IntRect uvRect;

	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void update(int row, float deltaTime, int movement);
};

#endif