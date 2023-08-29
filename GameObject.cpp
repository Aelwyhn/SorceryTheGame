#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char * textureSheet, int x, int y): x(x), y(y) {
    this->objectTexture = TextureManager::createTexture(textureSheet);
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
    TextureManager::draw(objectTexture, sourceRect, destinationRect);
}