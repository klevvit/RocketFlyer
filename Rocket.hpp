#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Rocket {

    const std::string IMAGE_PATH = "images/Rocket.png";

    sf::Texture texture;
    
    sf::Sprite sprite;

public:

    Rocket();

    void draw(sf::RenderWindow&);

};