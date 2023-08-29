#pragma once
#include "Game.h"


class Map {
    public:
        Map();
        ~Map();

        void loadMap(int newMap[20][25]);
        void drawMap();

    private:
        SDL_Rect sourceRect;
        SDL_Rect destinationRect;
        SDL_Texture* waterTexture;
        SDL_Texture* grassTexture;
        SDL_Texture* dirtTexture;

        int map[20][25];
};