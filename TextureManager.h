#pragma once

#include "SDL2/SDL.h"

class TextureManager {

    public:
        static SDL_Texture* createTexture(const char* fileName);
        static void draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect dest);
};