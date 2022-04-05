#pragma once

#include "Game.h"

static SDL_Color BLACK = { 0, 0, 0 };
static SDL_Color WHITE = { 255, 255, 255 };
static SDL_Color CYAN = { 0, 255, 255 };
static SDL_Color SILVER = { 192, 192, 192 };

SDL_Texture* loadTexture(std::string filename);
