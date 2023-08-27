#include "Game.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "external/include/SDL_image.h"
#include "Constants.h"

SDL_Texture *warriorTexture;
SDL_Rect sourceRect;
SDL_Rect destinationRect;
float counter;

Game::Game() {}

Game::~Game() {}

void Game::init(const char * title, int x, int y, int w, int h, bool isFullScreen) {
    int screenModeFlag = SDL_WINDOW_SHOWN;
    if(isFullScreen) {
        screenModeFlag = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(
            title,
            x, y,
            w, h,
            screenModeFlag
        );
        if(window) {
            renderer = SDL_CreateRenderer(window, -1, 0);

            if(renderer) {
                std::cout << "Renderer is initialized\n";
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
        }
        isGameRunning = true;

        SDL_Surface *surface = IMG_Load("assets/warrior.png");
        warriorTexture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
}

void Game::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isGameRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update() {
    counter += 1;
    if(counter >= GameConstants::SCREEN_WIDTH) {
        counter = 0;
    }
    destinationRect.h = 64;
    destinationRect.w = 64;
    destinationRect.x = counter;
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, warriorTexture, NULL, &destinationRect);
    SDL_RenderPresent(renderer);
}
void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Quit, clean\n";
}