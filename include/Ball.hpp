#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>

#include "Entity.hpp"
#include "Math.hpp"

class Ball : public Entity {
public:
    Ball(Vector2f p_pos, SDL_Texture* p_tex);
    Vector2f& getVelocity()
	{
		return velocity;
	}
    Vector2f& getInitialMousePos()
	{
		return initialMousePos;
	}
    void setInitialMousePos(float p_x, float p_y);
    void setVelocity(float p_x, float p_y);
    void update(double deltaTime, bool mouseDown, bool mousePressed);
private:
    Vector2f velocity;
    Vector2f target;
    Vector2f launchedVelocity;
    float velocity1D;
    float launchedVelocity1D;
    Vector2f initialMousePos;
    bool canMove = true;
    int dirX = 1;
    int dirY = 1;
    float friction = 0.005f;
};