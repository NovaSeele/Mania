#pragma once
#include"Game.h"
#include<random>

//-----------------Stat------------------//

static int ComboCount_str;



//----------------- Key1 ----------------//
const int Key1_WIDTH = 160;
const int Key1_HEIGHT = 40;
const int KEY_1_XPOS = 0;
    
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

    
    void reset1();
    void delete1();
    void update1();
    void render1();
    void record1();
    bool perfect();
    bool miss();
};
static Key1* key1;

//----------------- Key1 ----------------//





//----------------- Key2 ----------------//
const int Key2_WIDTH = 154;
const int Key2_HEIGHT = 40;
const int Key_2_XPOS = 164;
    
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


    void reset2();
    void delete2();
    void update2();
    void render2();
    void record2();
};
static Key2* key2;
//----------------- Key2 ----------------//





//----------------- Key3 ----------------//
const int Key3_WIDTH = 154;
const int Key3_HEIGHT = 40;
const int KEY_3_XPOS = 324;
    

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

   
    void reset3();
    void delete3();
    void update3();
    void render3();
    void record3();
};
static Key3* key3;
//----------------- Key3 ----------------//





//----------------- Key4 ----------------//
const int Key4_WIDTH = 158;
const int Key4_HEIGHT = 40;
const int KEY_4_XPOS = 483;

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

    
    void reset4();
    void delete4();
    void update4();
    void render4();
    void record4();
};
static Key4* key4;
//----------------- Key4 ----------------//





//-----------------Pattern---------------//
struct Pattern
{
    int cnt = 0; //count variable

	void patterncount();
    void speedcount();

    void speedup();
    void speeddown();


	void update();
};
static Pattern*pattern;
//-----------------Pattern---------------//





//------------------Combo----------------//
struct Combo
{
    int ComboCount;
    int xpos;
    int ypos;
    std::string combo_str;

    void combo_update();
    void combo_render();
    void combo_count();
    void combo_delete();
    void re_render();

    SDL_Texture* COMBO;
    SDL_Rect COMBO_Rect;

    Combo(std::string stringname);
    ~Combo();
};
static Combo* combo;
//------------------Combo----------------//




//------------------Score----------------//
struct Score
{
    int xpos;
    int ypos;


    int cnt;

    SDL_Texture* SCORE;
    SDL_Rect SCORE_rect;

    void scorecount();
    void updatescore();
    void renderscore();
    void deletescore();
    void score_resetanimation();

    Score(std::string stringname);
    ~Score();

};
static Score* score;
//------------------Score----------------//