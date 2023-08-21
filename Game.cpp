#include "Game.h"
#include "SDL2/SDL.h"

Game::Game() {}

Game::~Game() {}

void Game::init(const char * title, int x, int y, int w, int h, bool isFullScreen) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *sdlWindow = SDL_CreateWindow(
        "Sorcery",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );
    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);

    SDL_SetRenderDrawColor(sdlRenderer, 255, 50, 0, 100);
    SDL_RenderClear(sdlRenderer);
    SDL_RenderPresent(sdlRenderer);
    
    SDL_Delay(1500);
}

void Game::handleEvent() {}

void Game::update() {}

void Game::render() {}
void Game::clean() {}
bool Game::isRunning() { return true; }