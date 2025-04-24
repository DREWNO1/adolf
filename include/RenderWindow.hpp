#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"

class RenderWindow {
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    int getRefreshRate();
    void cleanUp();
    void clear();
    void render(Entity& p_entity);
	void render(int x, int y, SDL_Texture* p_tex);
    void display();
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};