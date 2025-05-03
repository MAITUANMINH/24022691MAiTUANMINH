#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#define WINDOW_TITLE "GAMEVUI"
const int SCREEN_WIDTH = 563;
const int SCREEN_HEIGHT = 1000;

struct Graphics
{
    SDL_Renderer *renderer;
	SDL_Window *window;

    void logErrorAndExit(const char* msg, const char* error);
	void init();
    void presentScene();
    SDL_Texture *loadTexture(const char *filename);
    void renderTexture (SDL_Texture *background);
};

#endif // GRAPHICS_H
