#include "Entity.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex) {
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
	SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
}


SDL_Texture* Entity::getTex() {
	return tex;
}

void Entity::update(double deltaTime) {}

void Entity::setPos(float p_x, float p_y) {
	pos.x = p_x;
	pos.y = p_y;
}

void Entity::setAngle(float p_angle) {
	angle = p_angle;
}

void Entity::setScale(float p_w, float p_h) {
	scale.x = p_w;
	scale.y = p_h;
}

SDL_Rect Entity::getCurrentFrame() {
	return currentFrame;
}