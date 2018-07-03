#include "Tile.h"
Tile::Tile(sf::Texture& tileSheet)
{
	//Set the collision box
	m_box.width = TILE_WIDTH;
	m_box.height = TILE_HEIGHT;
}

Tile::~Tile()
{
}

void Tile::setRectBox(sf::IntRect tempBox)
{
	m_box.left = tempBox.left;
	m_box.top = tempBox.top;

	tileSprite.setTextureRect(m_box);
}

void Tile::setTileType(int type)
{
	m_type = type;
}


sf::IntRect Tile::getBox()
{
	return m_box;
}

int Tile::getType()
{
	return m_type;
}
