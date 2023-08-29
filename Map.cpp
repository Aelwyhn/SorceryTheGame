#include "Map.h"
#include "TextureManager.h"
#include "Constants.h"

int level1Map[20][25] = {
    {0,0,0,1,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,2,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},

    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},

    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},

    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
    {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,}
};

Map::Map()
{
    dirtTexture = TextureManager::createTexture(GameConstants::DIRT_FILE);
    grassTexture = TextureManager::createTexture(GameConstants::GRASS_FILE);
    waterTexture = TextureManager::createTexture(GameConstants::WATER_FILE);

    loadMap(level1Map);

    sourceRect.x = 0;
    sourceRect.y = 0;
    sourceRect.w = 32;
    sourceRect.h = 32;
    
    destinationRect.x = 0;
    destinationRect.y = 0;
    destinationRect.w = 32;
    destinationRect.h = 32;

}

void Map::loadMap(int newMap[20][25])
{
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 25; col++)
        {
            map[row][col] = newMap[row][col];
        }
    }
}

void Map::drawMap()
{
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 25; col++)
        {
            destinationRect.x = col * 32;
            destinationRect.y = row * 32;
   
            switch(map[row][col])
            {
                case 0:
                    TextureManager::draw(waterTexture, sourceRect, destinationRect);
                    break;
                case 1:
                    TextureManager::draw(grassTexture, sourceRect, destinationRect);
                    break;
                case 2:
                    TextureManager::draw(dirtTexture, sourceRect, destinationRect);
                    break;
                default:
                    break;
            }
        }
    }
}