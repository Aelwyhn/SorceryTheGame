#pragma once
#include "SDL2/SDL.h"

class Game {
public:
        Game();
        ~Game();

        void init(const char * title, int x, int y, int w, int h, bool isFullScreen);
        void handleEvent();
        void update();
        void render();
        void clean();
        bool isRunning() { return isGameRunning; }

        static SDL_Renderer *renderer;
private:
    bool isGameRunning;
    SDL_Window *window;
};