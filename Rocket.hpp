#pragma once

#include <string>
#include <chrono>

#include <SFML/Graphics.hpp>

class Rocket {

    const std::string IMAGE_PATH = "images/Rocket.png";

    sf::Texture texture;
    sf::Sprite sprite;

    float x;
    float y;
    float speedX;
    float speedY;

    std::chrono::steady_clock::time_point time;

public:

    Rocket();

    void updatePosition();

    void draw(sf::RenderWindow &);

};