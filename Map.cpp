#include "Map.h"
#include"TextureManager.h"

Map::Map(std::string fileName)
{
    image = loadTexture(fileName);
}

Map::~Map()
{}

void Map::loadMap()
{
    SDL_RenderCopy(Game::renderer, image, NULL, NULL);
}

void Map::drawMap()
{

}