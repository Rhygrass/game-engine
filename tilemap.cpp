#include "tilemap.h"

bool TileMap::load(const std::string& tileSet, sf::Vector2u tileSize, const int* tiles, unsigned int levelWidth, unsigned int levelHeight)
{
	//Load the tileSet texture
	if (!this->tileSet.loadFromFile(tileSet))
		return false;

	//Resize VertexArray to fit the defined level size
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(levelWidth * levelHeight * 4);

	//Populate VertexArray with one quad per tile (one square per tile)
	for (unsigned int i = 0; i < levelWidth; ++i)
	{
		for (unsigned int j = 0; j < levelHeight; ++j)
		{
			//Get current tile number
			int tileNumber = tiles[i + j * levelWidth];

			//Find the tile position in the tileset texture map
			int tu = tileNumber % (this->tileSet.getSize().x / tileSize.x);
			int tv = tileNumber / (this->tileSet.getSize().x / tileSize.x);

			//Get a pointer to the current tile's quad
			sf::Vertex* quad = &vertices[(i + j * levelWidth) * 4];

			//Define the quad tile pointer's corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			//Define the quad tile pointer's texture map coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}
	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Apply the transform
	states.transform *= getTransform();

	//Apply the tileset texture
	states.texture = &tileSet;

	//Draw the VertexArray
	target.draw(vertices, states);
}