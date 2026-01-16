#include <Window.h>

int SDL_WindowInit() {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    else {
        //Create window
        SDLWindow = SDL_CreateWindow("Silver Octo Waddle", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if (SDLWindow == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return 1;
        }
        else {
            //Get window surface
            //gScreenSurface = SDL_GetWindowSurface(SDLWindow);
        }
    }
    return 0;
}

void SDL_WindowClose() {
    // Deallocate surfaces
    /*for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
    {
        SDL_DestroySurface(gKeyPressSurfaces[i]);
        gKeyPressSurfaces[i] = NULL;
    }*/

    // Destroy window
    SDL_DestroyWindow(SDLWindow);
    SDLWindow = NULL;

    // Quit SDL subsystems
    SDL_Quit();
}

void SDL_WindowRender() {
    const SDL_PixelFormatDetails* format = SDL_GetPixelFormatDetails(
        SDL_WindowGetSurface()->format
    );

    SDL_FillSurfaceRect(
        SDL_WindowGetSurface(),
        NULL,
        SDL_MapRGB(format, NULL, 50, 50, 50)
    );
}

void SDL_WindowUpdate() {
    SDL_UpdateWindowSurface(SDLWindow);
}

SDL_Surface* SDL_WindowGetSurface() {
    return SDL_GetWindowSurface(SDLWindow);
}