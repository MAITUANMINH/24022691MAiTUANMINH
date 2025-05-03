
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Player.h"

Player::Player(int startX, int startY) : x(startX), y(startY) {
    rect = { x, y, 50, 20 };
}

void Player::move(int dx) {
    x += dx;
    if (x < 0) x = 0;
    if (x > 750) x = 750;
    rect.x = x;
}

void Player::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

int Player::getX() { return x; }
int Player::getY() { return y; }

SDL_Rect Player:: getRect ()
{
    return rect;
}
