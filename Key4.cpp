#include "Key4.h"
#include"TextureManager.h"
#include"Game.h"

Key4::Key4(std::string fileName)
{
    image = loadTexture(fileName);

    srcRect.w = Key4_WIDTH;
    srcRect.h = Key4_HEIGHT;

    xpos = KEY_4_XPOS;
    ypos = KEY_4_YPOS;

    speed = Key4_SPEED;
}

Key4::~Key4()
{}


void Key4::speedup()
{
    speed += 0.5;
}

void Key4::reset()
{
    ypos = KEY_4_YPOS;
}

void Key4::update()
{
    ypos += speed;
    if (ypos >= 840)
    {
        ypos = 1;
        speed = Key4_SPEED;
    }
    srcRect.x = xpos;
    srcRect.y = ypos;
}

void Key4::perfect()
{

}

void Key4::great()
{

}

void Key4::fail()
{

}

void Key4::render()
{
    SDL_RenderCopy(Game::renderer, image, NULL, &srcRect);
}
