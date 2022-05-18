#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Object
{

public:
    const sf::Sprite &getSprite();

protected:
    Object();

    sf::Texture texture;
    sf::Sprite sprite;
};