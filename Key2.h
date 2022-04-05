#pragma once
#include"Game.h"
#include<random>


const double Key2_WIDTH = 154;
const double Key2_HEIGHT = 40;

const double Key_2_XPOS = 164;
const double Key_2_YPOS = -200;    //write random function here

const double Key2_SPEED = 10;


struct Key2
{
    double speed;  // the speed of Key2

    // ---- position of Key2 ---- //
    double xpos;
    double ypos;
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






