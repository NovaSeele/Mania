#pragma once
#include"Game.h"
#include<random>


const double Key3_WIDTH = 154;
const double Key3_HEIGHT = 40;

const double KEY_3_XPOS = 324;
const double KEY_3_YPOS = -100;    //write random function here

const double Key3_SPEED = 10;


struct Key3
{
    double speed;  // the speed of key

    // ---- position of Key ---- //
    double xpos;
    double ypos;
    // -----------------------------//

    SDL_Texture* image; // image of key
    SDL_Rect srcRect;   // shape of key

    Key3(std::string fileName);
    ~Key3();

    void speedup();
    void reset();

    void perfect();
    void great();
    void fail();

    void update();
    void render();
};

static Key3* key3;






