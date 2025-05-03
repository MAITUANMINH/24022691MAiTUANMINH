
#ifndef BULLET_H
#define BULLET_H

#include <SDL.h>

class Bullet {
private:
    int x, y;
    SDL_Rect rect;
public:
    Bullet(int startX, int startY);
    void update();
    void draw(SDL_Renderer* renderer);
    SDL_Rect getRect();
};

#endif

