#include "Grid.h"

Grid::Grid()
{
	setClips();

	if (loadTileSheet())
	{
		for (int i = 0; i < ROW_TILES; i++)
		{
			for (int j = 0; j < COLUMN_TILES; j++)
			{
				m_map[i][j] = new Tile(m_tileSheetTexture);
				m_map[i][j]->tileSprite.setPosition(float(i * TILE_WIDTH), float(j * TILE_HEIGHT));
				m_map[i][j]->setTileType(0);
				m_map[i][j]->isDrawn = false;
			}
		}

		m_tileSheetSprite.setTexture(m_tileSheetTexture);
		m_tileSheetSprite.setPosition((float)SCREEN_WIDTH, 0);
	}

}

Grid::~Grid()
{
	//delete [] map;
}


void Grid::drawTileSheet(sf::RenderWindow & window)
{
	window.draw(m_tileSheetSprite);
}

void Grid::drawTiles(sf::RenderWindow & window)
{
	for (int i = 0; i < ROW_TILES; i++)
	{
		for (int j = 0; j < COLUMN_TILES; j++)
		{
			window.draw(m_map[i][j]->getTileSprite());
		}
	}
}

bool Grid::loadTileSheet()
{
	if (!m_tileSheetTexture.loadFromFile("dungeon_tileSheet.png"))
	{
		return false;
	}

	m_tileSheetTexture.setRepeated(true);

	return true;
}

void Grid::saveToFile()
{
	std::ofstream map;
	map.open("levels/level1.txt");

	int rowCount = 0;
	for (int i = 0; i < COLUMN_TILES; i++)
	{
		for (int j = 0; j < ROW_TILES; j++)
		{
			auto type = m_map[j][i]->getType();
			map << m_map[j][i]->getType() << " ";
			rowCount++;
			if (rowCount == ROW_TILES)
			{
				rowCount = 0;
				map << '\n';
			}
		}
	}

	map.close();
}

void Grid::setClips()
{
	//Clip the sprite sheet
	m_clips[FLOOR].left = 64;
	m_clips[FLOOR].top = 128;
	m_clips[FLOOR].width = TILE_WIDTH;
	m_clips[FLOOR].height = TILE_HEIGHT;

	m_clips[DOOR].left = 0;
	m_clips[DOOR].top = 64;
	m_clips[DOOR].width = TILE_WIDTH;
	m_clips[DOOR].height = TILE_HEIGHT;

	m_clips[WALL_FIRE].left = 0;
	m_clips[WALL_FIRE].top = 0;
	m_clips[WALL_FIRE].width = TILE_WIDTH;
	m_clips[WALL_FIRE].height = TILE_HEIGHT;

	m_clips[WALL].left = 0;
	m_clips[WALL].top = 128;
	m_clips[WALL].width = TILE_WIDTH;
	m_clips[WALL].height = TILE_HEIGHT;

	m_clips[LADDER_TOP_LEFT].left = 64;
	m_clips[LADDER_TOP_LEFT].top = 0;
	m_clips[LADDER_TOP_LEFT].width = TILE_WIDTH;
	m_clips[LADDER_TOP_LEFT].height = TILE_HEIGHT;

	m_clips[LADDER_TOP_RIGHT].left = 128;
	m_clips[LADDER_TOP_RIGHT].top = 0;
	m_clips[LADDER_TOP_RIGHT].width = TILE_WIDTH;
	m_clips[LADDER_TOP_RIGHT].height = TILE_HEIGHT;

	m_clips[LADDER_BOTTOM_LEFT].left = 64;
	m_clips[LADDER_BOTTOM_LEFT].top = 64;
	m_clips[LADDER_BOTTOM_LEFT].width = TILE_WIDTH;
	m_clips[LADDER_BOTTOM_LEFT].height = TILE_HEIGHT;

	m_clips[LADDER_BOTTOM_RIGHT].left = 128;
	m_clips[LADDER_BOTTOM_RIGHT].top = 64;
	m_clips[LADDER_BOTTOM_RIGHT].width = TILE_WIDTH;
	m_clips[LADDER_BOTTOM_RIGHT].height = TILE_HEIGHT;

	m_clips[BORDER_TOP_LEFT].left = 0;
	m_clips[BORDER_TOP_LEFT].top = 192;
	m_clips[BORDER_TOP_LEFT].width = TILE_WIDTH;
	m_clips[BORDER_TOP_LEFT].height = TILE_HEIGHT;

	m_clips[BORDER_TOP_RIGHT].left = 128;
	m_clips[BORDER_TOP_RIGHT].top = 192;
	m_clips[BORDER_TOP_RIGHT].width = TILE_WIDTH;
	m_clips[BORDER_TOP_RIGHT].height = TILE_HEIGHT;

	m_clips[BORDER_BOTTOM_LEFT].left = 0;
	m_clips[BORDER_BOTTOM_LEFT].top = 320;
	m_clips[BORDER_BOTTOM_LEFT].width = TILE_WIDTH;
	m_clips[BORDER_BOTTOM_LEFT].height = TILE_HEIGHT;

	m_clips[BORDER_BOTTOM_RIGHT].left = 128;
	m_clips[BORDER_BOTTOM_RIGHT].top = 320;
	m_clips[BORDER_BOTTOM_RIGHT].width = TILE_WIDTH;
	m_clips[BORDER_BOTTOM_RIGHT].height = TILE_HEIGHT;

	m_clips[BORDER_LEFT].left = 0;
	m_clips[BORDER_LEFT].top = 256;
	m_clips[BORDER_LEFT].width = TILE_WIDTH;
	m_clips[BORDER_LEFT].height = TILE_HEIGHT;

	m_clips[BORDER_TOP].left = 64;
	m_clips[BORDER_TOP].top = 192;
	m_clips[BORDER_TOP].width = TILE_WIDTH;
	m_clips[BORDER_TOP].height = TILE_HEIGHT;

	m_clips[BORDER_RIGHT].left = 128;
	m_clips[BORDER_RIGHT].top = 256;
	m_clips[BORDER_RIGHT].width = TILE_WIDTH;
	m_clips[BORDER_RIGHT].height = TILE_HEIGHT;

	m_clips[BORDER_DOWN].left = 0;
	m_clips[BORDER_DOWN].top = 256;
	m_clips[BORDER_DOWN].width = TILE_WIDTH;
	m_clips[BORDER_DOWN].height = TILE_HEIGHT;

	m_clips[BORDER_DOWN].left = 64;
	m_clips[BORDER_DOWN].top = 320;
	m_clips[BORDER_DOWN].width = TILE_WIDTH;
	m_clips[BORDER_DOWN].height = TILE_HEIGHT;

	m_clips[TREASURE].left = 64;
	m_clips[TREASURE].top = 256;
	m_clips[TREASURE].width = TILE_WIDTH;
	m_clips[TREASURE].height = TILE_HEIGHT;
}

