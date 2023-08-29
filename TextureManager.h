#pragma once

#include "SDL2/SDL.h"

class TextureManager {

    public:
        static SDL_Texture* createTexture(const char* fileName);
};