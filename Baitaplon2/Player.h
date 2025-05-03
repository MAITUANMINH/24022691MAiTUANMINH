
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

class Player {
private:
    int x, y;
    SDL_Rect rect;
public:
    Player(int startX, int startY);
    void move(int dx);
    void draw(SDL_Renderer* renderer);
    int getX();
    int getY();
    SDL_Rect getRect();
};

#endif

