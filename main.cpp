#include "Game.h"
#include "SDL2/SDL.h"
#include "Constants.h"

Game *game = nullptr;

int main(int argc, char** argv) {

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init(
        "Sorcery game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT,
        false
    );

    while(game->isRunning()) {
        frameStart = SDL_GetTicks();

        game->handleEvent();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < GameConstants::EXPECTED_FRAME_DURATION) {
            SDL_Delay(GameConstants::EXPECTED_FRAME_DURATION - frameTime);
        }
    }

    game->clean();
    delete game;

    return 0;
}