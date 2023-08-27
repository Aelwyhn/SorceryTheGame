#include "external/include/SDL_image.h"
#include "TextureManager.h"

SDL_Texture* TextureManager::createTexture(const char* fileName, SDL_Renderer* renderer) {
    SDL_Surface *surface = IMG_Load(fileName);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}