#include "Object.hpp"

Object::Object(const std::string &imgPath)
{
    texture.loadFromFile(imgPath);
    sprite.setTexture(texture);
}

const sf::Sprite &Object::getSprite()
{
    return sprite;
}