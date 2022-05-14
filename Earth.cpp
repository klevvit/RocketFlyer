#include "Earth.hpp"
#include "consts.hpp"

const std::string Earth::IMAGE_PATH = "images/Earth.png";


Earth::Earth() {

    texture.loadFromFile(IMAGE_PATH);
    sprite.setTexture(texture);

    y = static_cast<float>(consts::WINDOW_HEIGHT);

    sprite.setOrigin(0, texture.getSize().y);

    sprite.setPosition(0, y);
    sprite.setScale(sf::Vector2f(4.f, 4.f));
}

void Earth::draw(sf::RenderWindow& window) {
    
    window.draw(sprite);
}