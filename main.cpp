#include "SDL2/SDL.h"

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *sdlWindow = SDL_CreateWindow(
        "Sorcery",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );
    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);

    SDL_SetRenderDrawColor(sdlRenderer, 255, 200, 0, 100);
    SDL_RenderClear(sdlRenderer);
    SDL_RenderPresent(sdlRenderer);
    
    SDL_Delay(1500);

    return 0;
}