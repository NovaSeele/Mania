#pragma once
#include"Game.h"
#include<random>


const int Key3_WIDTH = 154;
const int Key3_HEIGHT = 40;

const int KEY_3_XPOS = 324;
const int KEY_3_YPOS = -100;    //write random function here

const int Key3_SPEED = 10;


struct Key3
{
    int speed;  // the speed of key

    // ---- position of Key ---- //
    int xpos;
    int ypos;
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






