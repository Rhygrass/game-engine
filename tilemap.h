#ifndef _TILEMAP_H_
#define _TILEMAP_H_
#include <SFML\Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
private:
	sf::VertexArray vertices;
	sf::Texture tileSet;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	bool load(const std::string& tileSet, sf::Vector2u tileSize, const int* numTiles, unsigned int levelWidth, unsigned int levelHeight);

};

#endif