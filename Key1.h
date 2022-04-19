#pragma once
#include"Game.h"
#include<random>


const int Key1_WIDTH = 158;
const int Key1_HEIGHT = 40;

const int KEY_1_XPOS = 0;
const int KEY_1_YPOS = 1;    //write random function here

const int Key1_SPEED = 10;


struct Key1
{
    int speed;  // the speed of key

    // ---- position of Key ---- //
    int xpos;
    int ypos;
    // -----------------------------//

    SDL_Texture* image; // image of key
    SDL_Rect srcRect;   // shape of key

    Key1(std::string fileName);
    ~Key1();

    void speedup();
    void reset();

    void perfect();
    void great();
    void fail();

    void update();
    void render();
};
static Key1* key1;






