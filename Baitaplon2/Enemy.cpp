
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int x, int y) {
    rect = { x, y, 40, 40 };
}

void Enemy::update() {
    rect.y += 2;
}

void Enemy::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Enemy::getRect() {
    return rect;
}
