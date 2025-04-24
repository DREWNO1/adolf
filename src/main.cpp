#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cmath>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Ball.hpp"

bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    std::cout << "ERROR::WINDOW::STD_INIT_FAILED\nSDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "ERROR::WINDOW::IMG_INIT_FAILED\nSDL_ERROR: " << SDL_GetError() << std::endl;

    return true;
}

bool SDLinit = init();

RenderWindow window("Golf v1.0", 1280, 720);

SDL_Texture* ballTexture = window.loadTexture("res/gfx/ball.png");
SDL_Texture* bgTexture = window.loadTexture("res/gfx/bg.png");

Ball ball(Vector2f(1280/2, 720/2), ballTexture);

bool gameRunning = true;
bool mouseDown = false;
bool mousePressed = false;

bool swingPlayed = false;
bool secondSwingPlayed = false;

SDL_Event event;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

void update()
{	
	lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

	mousePressed = false;
	//Get our controls and events
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = true;
				mousePressed = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = false;
			}
			break;
		}
	}
	ball.update(deltaTime, mouseDown, mousePressed);
}

void graphics()
{
	window.clear();
	window.render(0, 0, bgTexture);
	window.render(ball);

	
	window.display();
}


void game()
{
	update();
    graphics();
}

int main(int argc, char* args[]) {

    while (gameRunning)
	{
		game();
	}

    window.cleanUp();
    SDL_Quit();

    return 0;
}