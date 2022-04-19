#pragma once
#include"Game.h"
#include<random>


const int Key2_WIDTH = 154;
const int Key2_HEIGHT = 40;

const int Key_2_XPOS = 164;
const int Key_2_YPOS = -200;    //write random function here

const int Key2_SPEED = 10;


struct Key2
{
    int speed;  // the speed of Key2

    // ---- position of Key2 ---- //
    int xpos;
    int ypos;
    // -----------------------------//

    SDL_Texture* image; // image of Key2
    SDL_Rect srcRect;   // shape of Key2

    Key2(std::string fileName);
    ~Key2();

    void speedup();
    void reset();

    void perfect();
    void great();
    void fail();

    void update();
    void render();
};

static Key2* key2;






