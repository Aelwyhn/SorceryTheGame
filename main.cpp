#include "Game.h"
#include "SDL2/SDL.h"
#include "Constants.h"

Game *game = nullptr;

int main(int argc, char** argv) {
    game = new Game();

    game->init(
        "Sorcery game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT,
        false
    );

    while(game->isRunning()) {
        game->handleEvent();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}