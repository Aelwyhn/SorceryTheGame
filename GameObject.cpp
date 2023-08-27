#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char * textureSheet, SDL_Renderer * renderer, int x, int y): x(x), y(y), renderer(renderer) {
    this->objectTexture = TextureManager::createTexture(textureSheet, renderer);
}

void GameObject::update() {
    x++;
    y++;
    sourceRect.w = 32;
    sourceRect.h = 32;
    sourceRect.x = 0;
    sourceRect.y = 0;
    destinationRect.x = x;
    destinationRect.y = y;
    destinationRect.w = sourceRect.w * 2;
    destinationRect.h = sourceRect.h * 2;
}

void GameObject::render() {
    SDL_RenderCopy(renderer, objectTexture, &sourceRect, &destinationRect);
}