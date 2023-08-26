#include "Game.h"
#include "SDL2/SDL.h"

Game *game = nullptr;

int main(int argc, char** argv) {
    game = new Game();

    game->init(
        "Sorcery game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
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