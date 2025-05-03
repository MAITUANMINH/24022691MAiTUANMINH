#ifndef ENEMY_H
#define ENEMY_H

#include <SDL.h>

class Enemy {
private:
    int x, y;
    SDL_Rect rect;
public:
    Enemy(int startX, int startY);
    void update();
    void draw(SDL_Renderer* renderer);
    SDL_Rect getRect();
};

#endif

