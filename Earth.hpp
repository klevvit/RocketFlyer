#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Earth
{

    static const std::string IMAGE_PATH;

    sf::Texture texture;
    sf::Sprite sprite;

    float y;

public:
    Earth();

    const sf::Sprite &getSprite();
};