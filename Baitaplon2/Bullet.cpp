
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(int startX, int startY) : x(startX), y(startY) {
    rect = { x, y, 10, 20 };
}

void Bullet::update() {
    y -= 10;
    rect.y = y;
}

void Bullet::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Bullet::getRect() {
    return rect;
}
