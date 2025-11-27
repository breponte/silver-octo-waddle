#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
int init();

//Loads media
int loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

int init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    } else {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return 1;
        } else {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return 0;
}

int loadMedia() {
    // Load splash image
    gXOut = SDL_LoadBMP("x.bmp");
    if (gXOut == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", "x.bmp", SDL_GetError());
        return 1;
    }
    return 0;
}

void close() {
    // Deallocate surface
    SDL_DestroySurface(gXOut);
    gXOut = NULL;

    // Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* args[]) {
    // Start up SDL and create window
    if (init() != 0) {
        printf("Failed to initialize!\n");
        return 1;
    }
    // Load media
    if (loadMedia() != 0) {
        printf("Failed to load media!\n");
        return -1;
    }

    // Main loop flag
    int quit = 0;
    // Event handler
    SDL_Event e = { 0 };

    //While application is running
    while (!quit) {
		//Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_EVENT_QUIT) {
                quit = 1;
            }

            //Apply the image
            SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);

            //Update the surface
            SDL_UpdateWindowSurface(gWindow);
        }
    }

    // Free resources and close SDL
    close();

    return 0;
}