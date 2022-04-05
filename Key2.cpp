#include "Key2.h"
#include"TextureManager.h"
#include"Game.h"

Key2::Key2(std::string fileName)
{
    image = loadTexture(fileName);

    srcRect.w = Key2_WIDTH;
    srcRect.h = Key2_HEIGHT;

    xpos = Key_2_XPOS;
    ypos = Key_2_YPOS;

    speed = Key2_SPEED;
}

Key2::~Key2()
{}


void Key2::speedup()
{
    speed += 0.5;
}

void Key2::reset()
{
    ypos = Key_2_YPOS;
}

void Key2::update()
{
    ypos += speed;
    if (ypos >= 840)
    {
        ypos = 1;
        speed = Key2_SPEED;
    }
    srcRect.x = xpos;
    srcRect.y = ypos;
}

void Key2::perfect()
{

}

void Key2::great()
{

}

void Key2::fail()
{

}

void Key2::render()
{
    SDL_RenderCopy(Game::renderer, image, NULL, &srcRect);
}
