#include "Key1.h"

#include"TextureManager.h"
#include"Game.h"

Key1::Key1(std::string fileName)
{
    image = loadTexture(fileName);

    srcRect.w = Key1_WIDTH;
    srcRect.h = Key1_HEIGHT;

    xpos = KEY_1_XPOS;
    ypos = KEY_1_YPOS;

    speed = Key1_SPEED;
}

Key1::~Key1()
{}


void Key1::speedup()
{
    speed+=0.5;
}

void Key1::reset()
{
    ypos = KEY_1_YPOS;
}

void Key1::update()
{
    ypos+=speed;
    if (ypos >= 840)
    {
        ypos = 1;
        speed = Key1_SPEED;
    }
    srcRect.x = xpos;
    srcRect.y = ypos;
}

void Key1::perfect()
{

}

void Key1::great()
{

}

void Key1::fail()
{

}

void Key1::render()
{
    SDL_RenderCopy(Game::renderer, image, NULL, &srcRect);
}
