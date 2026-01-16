#pragma once
#include <SDL3/SDL.h>
#include <stdio.h>

// Screen dimension constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

SDL_Window* SDLWindow;

int SDL_WindowInit();
void SDL_WindowClose();
void SDL_WindowRender();
void SDL_WindowUpdate();
SDL_Surface* SDL_WindowGetSurface();