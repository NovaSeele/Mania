#include "Game.h"
#include"TextureManager.h"
#include"Key1.h"
#include"Key2.h"
#include"Key3.h"
#include"Key4.h"
#include"Map.h"
#include"KeyPattern.h"
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
		pattern->patterncount();
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			key1->speedup();
			key1->reset();
			break;
		case SDLK_s:
			key2->speedup();
			key2->reset();
			break;
		case SDLK_j:
			key3->speedup();
			key3->reset();
			break;
		case SDLK_k:
			key4->speedup();
			key4->reset();
			break;
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		}
	default:
		break;
	}
}

void Game::update()
{
	pattern->changepattern();
	pattern->update();


	key1->update();
	key2->update();
	key3->update();
	key4->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	background->loadMap();
	background->drawMap();
	key1->render();
	key2->render();
	key3->render();
	key4->render();	 
	SDL_RenderPresent(renderer);							
}

void Game::clean()
{
	delete[] key1;
	key1 = NULL;

	delete[] key2;
	key2 = NULL;

	delete[] key3;
	key3 = NULL;

	delete[] key4;
	key4 = NULL;

	delete[] background;
	background = NULL;

	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	IMG_Quit();
	SDL_Quit();
}