#include "Ball.hpp"
#include "Entity.hpp"
#include "Math.hpp"

#include <iostream>
#include <cmath>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Ball::Ball(Vector2f p_pos, SDL_Texture* p_tex):Entity(p_pos, p_tex) {}

void Ball::setVelocity(float p_x, float p_y) {
    velocity.x = p_x;
    velocity.y = p_y;
}

void Ball::setInitialMousePos(float p_x, float p_y) {
    initialMousePos.x = p_x;
    initialMousePos.y = p_y;
}

void Ball::update(double deltaTime, bool mouseDown, bool mousePressed)
{
        // Inicjalizacja myszki
        int mouseX = 0, mouseY = 0;
        SDL_GetMouseState(&mouseX, &mouseY);
    
        // Gdy kliknięto w piłkę - zapisujemy pozycję początkową
        if (mousePressed && canMove)
        {
            setInitialMousePos(mouseX, mouseY);
        }
    
        // Gdy mysz jest przeciągana - ustawiamy prędkość
        if (mouseDown && canMove)
        {
            setVelocity((mouseX - getInitialMousePos().x) / -100.0f,
                        (mouseY - getInitialMousePos().y) / -100.0f);
    
            // Kierunek wektora
            dirX = velocity.x / abs(velocity.x);
            dirY = velocity.y / abs(velocity.y);
    
            // Obliczamy skalarną prędkość i zapisujemy prędkość początkową
            velocity1D = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
            launchedVelocity1D = velocity1D;
            launchedVelocity = velocity;
    
            // Ograniczenie maksymalnej prędkości
            if (velocity1D > 0.5f)
            {
                velocity1D = 0.5f;
                launchedVelocity1D = 0.5f;
            }
        }
        else
        {
            canMove = false;
    
            // Aktualizacja pozycji
            setPos(getPos().x + getVelocity().x * deltaTime,
                   getPos().y + getVelocity().y * deltaTime);
    
            // Jeśli prędkość > 0 - stosujemy tarcie
            if (velocity1D > 0.0001f)
            {
                velocity1D *= (1.0f - friction * deltaTime);
                if (velocity1D < 0.001f) velocity1D = 0.0f;
    
                // Utrzymanie kierunku i proporcji pierwotnej prędkości
                velocity.x = (velocity1D / launchedVelocity1D) * abs(launchedVelocity.x) * dirX;
                velocity.y = (velocity1D / launchedVelocity1D) * abs(launchedVelocity.y) * dirY;
            }
            else
            {
                // Zatrzymanie piłki
                setVelocity(0, 0);
                SDL_GetMouseState(&mouseX, &mouseY);
                setInitialMousePos(mouseX, mouseY);
                canMove = true;
            }

        const float bounceDamping = 1.0f;

        if ( getPos().x + getCurrentFrame().w > 1260)
        {
            getPos().x = 1260 - getCurrentFrame().w;
            getVelocity().x = -abs(getVelocity().x) * bounceDamping;
            dirX = -1;
        }
        
        else if ( getPos().x < 20)
        {
            getPos().x = 20;
            getVelocity().x = abs(getVelocity().x) * bounceDamping;
            dirX = 1;
        }
        
        if (getPos().y + getCurrentFrame().h > 700)
        {
            getPos().y = 700 - getCurrentFrame().h;
            getVelocity().y = -abs(getVelocity().y) * bounceDamping;
            dirY = -1;
        }
        
        else if (getPos().y < 20)
        {
            getPos().y = 20;
            getVelocity().y = abs(getVelocity().y) * bounceDamping;
            dirY = 1;
        }
        
        setPos(getPos().x, getPos().y);
        setVelocity(getVelocity().x, getVelocity().y);
    }
    
}