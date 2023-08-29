#include "external/include/SDL_image.h"
#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::createTexture(const char* fileName) {
    SDL_Surface *surface = IMG_Load(fileName);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, texture, &source, &dest);
}