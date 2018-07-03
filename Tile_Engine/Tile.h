#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"

class Tile
{
public:

	Tile(sf::Texture& tileSheet);
	~Tile();

	void setRectBox(sf::IntRect tempBox);
	void setTileType(int type);

	//Get the collision box
	sf::IntRect getBox();
	sf::Sprite& getTileSprite() { return tileSprite; }
	//Get the tile type
	int getType();

	bool isDrawn;

	sf::Sprite tileSprite;
private:

	//The attributes of the tile
	sf::IntRect m_box;

	//The tile type
	int m_type;
};