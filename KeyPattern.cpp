#include "KeyPattern.h"
#include"Game.h"
#include"TextureManager.h"
#include<string>


int temp1 = rand() % 10 - (rand() % 100 + 200);
int temp2 = rand() % 10 - (rand() % 100 + 200);
int temp3 = rand() % 10 - (rand() % 100 + 200);
int temp4 = rand() % 10 - (rand() % 100 + 200);


int Key_SPEED = 25;
int NOTE_SPEED = Key_SPEED;


int KEY_1_YPOS = temp1;
int KEY_2_YPOS = temp2;
int KEY_3_YPOS = temp3;
int KEY_4_YPOS = temp4;


int KEY_1_YPOS_RECORD = 0;
int KEY_2_YPOS_RECORD = 0;
int KEY_3_YPOS_RECORD = 0;
int KEY_4_YPOS_RECORD = 0;



//------------------ Key1 -------------------//
Key1::Key1(std::string fileName)
{
    image = loadTexture(fileName);

    srcRect.w = Key1_WIDTH;
    srcRect.h = Key1_HEIGHT;

    xpos = KEY_1_XPOS;
    ypos = KEY_1_YPOS;

    speed = Key_SPEED;
}

Key1::~Key1()
{}

void Key1::delete1()
{
    delete[] key1;
    key1 = NULL;
}

void Key1::reset1()
{
    if (ypos >= 750)
    {
        ypos = KEY_1_YPOS;
    }
}

void Key1::record1()
{
    if (ypos >= 750)
    {
        KEY_1_YPOS_RECORD = ypos;
    }
}

void Key1::update1()
{
    ypos += speed;
    if (ypos >= 840)
    {
        KEY_1_YPOS_RECORD = ypos;
        ypos = KEY_1_YPOS;
        speed = Key_SPEED;
    }
    srcRect.x = xpos;
    srcRect.y = ypos;   
    std::cout << KEY_1_YPOS_RECORD << " ";
}

bool Key1::perfect()
{
    if (KEY_1_YPOS_RECORD >= 750 && KEY_1_YPOS_RECORD < 840)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Key1::miss()
{
    if (KEY_1_YPOS_RECORD >= 840)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Key1::render1()
{
    SDL_RenderCopy(Game::renderer, image, NULL, &srcRect);
}
//------------------ Key1 -------------------//





//------------------ Key2 -------------------//
Key2::Key2(std::string fileName)
{
    image = loadTexture(fileName);

    srcRect.w = Key2_WIDTH;
    srcRect.h = Key2_HEIGHT;

    xpos = Key_2_XPOS;
    ypos = KEY_2_YPOS;

    speed = Key_SPEED;
}

Key2::~Key2()
{}

void Key2::reset2()
{
    if (ypos >= 750)
    {
        ypos = KEY_2_YPOS;
    }
}

void Key2::record2()
{
    if (ypos >= 750)
    {
        KEY_2_YPOS_RECORD = ypos;
    }
}

void Key2::delete2()
{
    delete[] key2;
    key2 = NULL;
}

void Key2::update2()
{
    ypos += speed;
    if (ypos >= 840)
    {
        KEY_2_YPOS_RECORD = ypos;
        ypos = KEY_2_YPOS;
        speed = Key_SPEED;
    }
    srcRect.x = xpos;
    srcRect.y = ypos;
}

void Key2::render2()
{
    SDL_RenderCopy(Game::renderer, image, NULL, &srcRect);
}

//------------------ Key2 -------------------//





//------------------ Key3 -------------------//
Key3::Key3(std::string fileName)
{
    image = loadTexture(fileName);

    srcRect.w = Key3_WIDTH;
    srcRect.h = Key3_HEIGHT;

    xpos = KEY_3_XPOS;
    ypos = KEY_3_YPOS;

    speed = Key_SPEED;
}

Key3::~Key3()
{}

void Key3::reset3()
{
    if (ypos >= 750)
    {
        ypos = KEY_3_YPOS;
    }
}

void Key3::record3()
{
    if (ypos >= 750)
    {
        KEY_3_YPOS_RECORD = ypos;
    }
}

void Key3::delete3()
{
    delete[] key3;
    key3 = NULL;
}

void Key3::update3()
{
    ypos += speed;
    if (ypos >= 840)
    {
        KEY_3_YPOS_RECORD = ypos;
        ypos = KEY_3_YPOS;
        speed = Key_SPEED;
    }
    srcRect.x = xpos;
    srcRect.y = ypos;
}

void Key3::render3()
{
    SDL_RenderCopy(Game::renderer, image, NULL, &srcRect);
}

//------------------ Key3 -------------------//





//------------------ Key4 -------------------//
Key4::Key4(std::string fileName)
{
    image = loadTexture(fileName);

    srcRect.w = Key4_WIDTH;
    srcRect.h = Key4_HEIGHT;

    xpos = KEY_4_XPOS;
    ypos = KEY_4_YPOS;

    speed = Key_SPEED;
}

Key4::~Key4()
{}

void Key4::reset4()
{
    if (ypos >= 750)
    {
        ypos = KEY_4_YPOS;
    }
}

void Key4::record4()
{
    if (ypos >= 750)
    {
        KEY_4_YPOS_RECORD = ypos;
    }
}

void Key4::delete4()
{
    delete[] key4;
    key4 = NULL;
}

void Key4::update4()
{
    ypos += speed;
    if (ypos >= 840)
    {
        KEY_4_YPOS_RECORD = ypos;
        ypos = KEY_4_YPOS;
        speed = Key_SPEED;
    }
    srcRect.x = xpos;
    srcRect.y = ypos;
}

void Key4::render4()
{
    SDL_RenderCopy(Game::renderer, image, NULL, &srcRect);
}

//------------------ Key4 -------------------//




//------------------Pattern------------------//
void Pattern::patterncount()
{
    cnt++;
}

void Pattern::update()
{
	std::cout << cnt << " ";
    std::cout << NOTE_SPEED << std::endl;
}

void Pattern::speedup()
{
    Key_SPEED++;
}

void Pattern::speeddown()
{
    Key_SPEED--;
}

void Pattern::speedcount()
{
    NOTE_SPEED = Key_SPEED;
}
//------------------Pattern------------------//





//------------------Combo--------------------//
Combo::Combo(std::string stringname)
{
    COMBO = loadFont(stringname);
    COMBO_Rect.w = 70;
    COMBO_Rect.h = 50;

    xpos = 270;
    ypos = 150;

    ComboCount = 0;

}

Combo::~Combo()
{
    combo_delete();
}

void Combo::combo_count()
{
    if (KEY_1_YPOS_RECORD >= 750 && KEY_1_YPOS_RECORD < 840)
    {
        ComboCount++;
    }
    if (KEY_1_YPOS_RECORD >= 840)
    {
        ComboCount = 0;
    }
}



void Combo::combo_update()
{
    ComboCount_str = ComboCount;
    COMBO_Rect.x = xpos;
    COMBO_Rect.y = ypos;
    std::cout << ComboCount_str << " ";
}

void Combo::combo_render()
{
    SDL_RenderCopy(Game::renderer, COMBO, NULL, &COMBO_Rect);
}

void Combo::combo_delete()
{
    delete[] combo;
    combo = NULL;
}
void Combo::re_render()
{
    combo = new Combo("200");
}
//------------------Combo--------------------//





//------------------Score--------------------//
Score::Score(std::string stringname)
{
    SCORE = loadFont(stringname);
    SCORE_rect.w = 100;
    SCORE_rect.h = 55;

    xpos = 270;
    ypos = 100;

    cnt = 0;

}

Score::~Score()
{

}

void Score::scorecount()
{
}

void Score::score_resetanimation()
{
    cnt++;
    if (cnt >= 10)
    {
        ypos = -99999;
        SCORE_rect.y = ypos;
    }
    std::cout << cnt << " ";
}

void Score::deletescore()
{
    delete[] score;
    score = NULL;
}

void Score::updatescore()
{
    ypos = 100;
    cnt = 0;
    SCORE_rect.x = xpos;
    SCORE_rect.y = ypos;
}

void Score::renderscore()
{
    SDL_RenderCopy(Game::renderer, SCORE, NULL, &SCORE_rect);
}
//------------------Score---------------------//