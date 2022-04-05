#include "TextureManager.h"

SDL_Texture* loadTexture(std::string filename)
{
    SDL_Texture* optimal = NULL;

    SDL_Surface* loading = IMG_Load(filename.c_str());
    if (loading == NULL)
        printf("Failed to load image \n");
    else
        optimal = SDL_CreateTextureFromSurface(Game::renderer, loading);

    SDL_FreeSurface(loading);
    return optimal;
}
