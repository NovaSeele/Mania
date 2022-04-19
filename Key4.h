#pragma once
#include"Game.h"
#include<random>


const int Key4_WIDTH = 158;
const int Key4_HEIGHT = 40;

const int KEY_4_XPOS = 483;
const int KEY_4_YPOS = -300;    //write random function here

const int Key4_SPEED = 10;


struct Key4
{
    int speed;  // the speed of key

    // ---- position of Key ---- //
    int xpos;
    int ypos;
    // -----------------------------//

    SDL_Texture* image; // image of key
    SDL_Rect srcRect;   // shape of key

    Key4(std::string fileName);
    ~Key4();

    void speedup();
    void reset();

    void perfect();
    void great();
    void fail();

    void update();
    void render();
};

static Key4* key4;






