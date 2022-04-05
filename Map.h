#pragma once
#include"Game.h"
struct Map
{
    SDL_Texture* image;

    Map(std::string fileName);
    ~Map();
  
    void loadMap();
    void drawMap();
};

static Map* background;



