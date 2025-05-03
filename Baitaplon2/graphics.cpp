#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"

void Graphics::logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}
void Graphics :: init ()
{
    if (SDL_Init(SDL_INIT_EVERYTHING)){
        logErrorAndExit ("SDL_Init", SDL_GetError());

    }
     window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        logErrorAndExit("SDL_Init", SDL_GetError());
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        logErrorAndExit("SDL_image error: ", IMG_GetError());
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if (renderer == nullptr)\
        logErrorAndExit("CreateRenderer", SDL_GetError());
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

}
void Graphics :: presentScene ()
{
    SDL_RenderPresent(renderer);
}

SDL_Texture * Graphics :: loadTexture (const char * filename)
{
    SDL_LogMessage (SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    SDL_Texture *texture = IMG_LoadTexture (renderer, filename);
    if (texture == nullptr)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());
    return texture;

}
void Graphics :: renderTexture (SDL_Texture *background)
{
    SDL_Rect dest;

    dest.x= 0;
    dest.y= 0;
    SDL_QueryTexture (background, NULL , NULL, &dest.w, &dest.h );

    SDL_RenderCopy (renderer, background, NULL, &dest);
}
