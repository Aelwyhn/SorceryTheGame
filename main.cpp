#include "Game.h"
#include "SDL2/SDL.h"

int main(int argc, char** argv) {
    Game *game = new Game();
    game->init("title", 1, 1, 1, 1, false);

    return 0;
}