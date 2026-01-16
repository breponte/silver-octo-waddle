#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <Window.h>

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WindowInit();

    bool IsRunning = true;
    SDL_Event Event;
    while (IsRunning) {
        while (SDL_PollEvent(&Event)) {
            if (Event.type == SDL_EVENT_QUIT) {
                IsRunning = false;
            }
        }

        SDL_WindowRender();
        SDL_WindowUpdate();
    }

    SDL_WindowClose();
    return 0;
}