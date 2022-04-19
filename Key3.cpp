#include "Key3.h"
#include"TextureManager.h"
#include"Game.h"

Key3::Key3(std::string fileName)
{
    image = loadTexture(fileName);

    srcRect.w = Key3_WIDTH;
    srcRect.h = Key3_HEIGHT;

    xpos = KEY_3_XPOS;
    ypos = KEY_3_YPOS;

    speed = Key3_SPEED;
}

Key3::~Key3()
{}


void Key3::speedup()
{
    speed += 1;
}

void Key3::reset()
{
    ypos = KEY_3_YPOS;
}

void Key3::update()
{
    ypos += speed;
    if (ypos >= 840)
    {
        ypos = 1;
        speed = Key3_SPEED;
    }
    srcRect.x = xpos;
    srcRect.y = ypos;
}

void Key3::perfect()
{

}

void Key3::great()
{

}

void Key3::fail()
{

}

void Key3::render()
{
    SDL_RenderCopy(Game::renderer, image, NULL, &srcRect);
}
