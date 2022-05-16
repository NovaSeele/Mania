#include"Game.h"
#include"TextureManager.h"
#include"Map.h"
#include"KeyPattern.h" 
#include<string>
#include"Lightning.h"


SDL_Renderer* Game::renderer = nullptr;


Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	key1 = new Key1("Image/Key1-4.png");
	key2 = new Key2("Image/Key2-3.png");
	key3 = new Key3("Image/Key2-3.png");
	key4 = new Key4("Image/Key1-4.png");
	background = new Map("Image/background.png");
	pattern = new Pattern();

	lightning1 = new Lightning1("Image/Key1-4 - Lightning.png");
	lightning2 = new Lightning2("Image/Key1-4 - Lightning.png");
	lightning3 = new Lightning3("Image/Key1-4 - Lightning.png");
	lightning4 = new Lightning4("Image/Key1-4 - Lightning.png");
}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		score->updatescore();
		combo->combo_count();
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			key1->record1(); 
			if (key1->perfect())
			{
				ScoreShow += 300;
				ComboShow++;
			}
			if (key1->miss())
			{
				ComboShow = 0;
			}
			key1->reset1();
			pattern->patterncount();
			lightning1->reset_lightning1();
			break;
		case SDLK_s:
			key2->record2();
			key2->reset2();
			pattern->patterncount();
			lightning2->reset_lightning2();
			break;
		case SDLK_j:
			key3->record3();
			key3->reset3();
			pattern->patterncount();
			lightning3->reset_lightning3();
			break;
		case SDLK_k:
			key4->record4();
			key4->reset4();
			pattern->patterncount();
			lightning4->reset_lightning4();
			break;
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		case SDLK_UP:
			pattern->speedup();
			pattern->speedcount();
			break;
		case SDLK_DOWN:
			pattern->speeddown();
			pattern->speedcount();
			break;
		}
	default:
		break;
	}
}

void Game::update()
{
	std::string combo_show = std::to_string(ComboShow);
	combo->combo_delete();
	combo = new Combo(combo_show);
	combo->combo_delete();
	std::cout << ComboShow << " ";


	std::string score_show = std::to_string(ScoreShow);
	score->deletescore();
	score = new Score("200");
	score->deletescore();
	std::cout << ScoreShow << " ";

	score->scorecount();
	pattern->update();

	lightning1->update_lightning1();
	key1->update1();

	lightning2->update_lightning2();
	key2->update2();

	lightning3->update_lightning3();
	key3->update3();

	key4->update4();
	lightning4->update_lightning4();

	score->score_resetanimation();
	combo->combo_update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	background->loadMap();
	background->drawMap();

	key1->render1();
	lightning1->render_lightning1();

	key2->render2();
	lightning2->render_lightning2();

	key3->render3();
	lightning3->render_lightning3();

	key4->render4();	
	lightning4->render_lightning4();

	score->renderscore();
	combo->combo_render();

	
	SDL_RenderPresent(renderer);							
}

void Game::clean()
{
	key1->delete1();
	lightning1->delete_lightning1();

	key2->delete2();
	lightning2->delete_lightning2();

	key3->delete3();
	lightning3->delete_lightning3();

	key4->delete4();
	lightning4->delete_lightning4();

	score->deletescore();
	combo->combo_delete();

	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	IMG_Quit();
	SDL_Quit();
}