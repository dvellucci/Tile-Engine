#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <iostream>
#include <math.h>  

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH + TILE_SHEET_WIDTH, SCREEN_HEIGHT), "SFML works!");

	Grid grid;

	//The tile offsets
	int x = 0, y = 0;

	sf::IntRect box;
	int currentType = FLOOR;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				int x = sf::Mouse::getPosition(window).x;
				int y = sf::Mouse::getPosition(window).y;

				int tilePosX = 0;
				int tilePosY = 0;

				//get the correct tile when clicking on the tileSheet
				if (grid.getTileSheetSprite().getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
				{

					int offSetX = x - (int)grid.getTileSheetSprite().getPosition().x;
					int offSetY = y - (int)grid.getTileSheetSprite().getPosition().y;

					int rectX = int(round(offSetX / TILE_WIDTH) * TILE_WIDTH);
					int rectY = int(round(offSetY / TILE_HEIGHT) * TILE_HEIGHT);

					//set the clipping box of the sprite to use 
					box.left = rectX;
					box.top = rectY;
					box.width = TILE_WIDTH;
					box.height = TILE_HEIGHT;

					std::cout << rectX << " " << rectY << std::endl;
				}

				//check if a valid tile sprite is clicked and get the type of tile
				bool validSprite = false;
				for (int i = 0; i < (sizeof(grid.m_clips) / sizeof(*grid.m_clips)); i++)
				{
					if (box == grid.m_clips[i])
					{
						validSprite = true;

						//all tiles above type 8 are different walls, so set them to the same type
						//since they can't be walked through
						if (i > 8)
							currentType = 9;
						else
							currentType = i;
						break;
					}
				}

				//make sure the sprite gets placed properly in the grid
				tilePosX = int(round(x / TILE_WIDTH)) * TILE_WIDTH;
				tilePosY = int(round(y / TILE_HEIGHT)) * TILE_HEIGHT;
				int cellPosX = tilePosX / TILE_WIDTH;
				int cellPosY = tilePosY / TILE_HEIGHT;

				if (cellPosX < ROW_TILES && validSprite)
				{
					grid.m_map[cellPosX][cellPosY]->getTileSprite().setTexture(grid.getTileSheetTexture());
					grid.m_map[cellPosX][cellPosY]->setRectBox(box);
					grid.m_map[cellPosX][cellPosY]->setTileType(currentType);
				}
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return)
				{
					grid.saveToFile();
				}
				else if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}

		window.clear();
		grid.drawTileSheet(window);
		grid.drawTiles(window);
		window.display();
	}

	return 0;
}