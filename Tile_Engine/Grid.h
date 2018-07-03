#pragma once
#include "Data.h"
#include "Tile.h"
#include <memory>
#include <fstream>
#include <iostream>

class Grid
{
public:
	Grid();
	~Grid();

	void drawTileSheet(sf::RenderWindow& window);
	void drawTiles(sf::RenderWindow& window);
	void setClips();
	void saveToFile();

	bool loadTileSheet();
	sf::Texture& getTileSheetTexture() { return m_tileSheetTexture; }
	sf::Sprite getTileSheetSprite() { return m_tileSheetSprite; }

	Tile *m_map[ROW_TILES][COLUMN_TILES];
	sf::IntRect m_clips[TILE_SPRITES];

private:

	sf::Texture m_tileSheetTexture;
	sf::Sprite m_tileSheetSprite;
};