
#ifndef COLLISION_H
#define COLLISION_H

#include <SDL.h>

inline bool checkCollision(SDL_Rect a, SDL_Rect b) {
    return SDL_HasIntersection(&a, &b);
}

#endif

