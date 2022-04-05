#pragma once
#include"Game.h"
#include<random>


const double Key1_WIDTH = 158;
const double Key1_HEIGHT = 40;

const double KEY_1_XPOS = 0;
const double KEY_1_YPOS = 1;    //write random function here

const double Key1_SPEED = 10;


struct Key1
{
    double speed;  // the speed of key

    // ---- position of Key ---- //
    double xpos;
    double ypos;
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






