#include <iostream>
#include <chrono>

#include <SFML/Graphics.hpp>

#include "Rocket.hpp"
#include "Earth.hpp"
#include "consts.hpp"

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(consts::WINDOW_WIDTH, consts::WINDOW_HEIGHT), "Rocket Flyer", sf::Style::Close);

    Rocket rocket;
    Earth earth;

    auto start = std::chrono::steady_clock::now();

    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        rocket.updatePosition();

        window.clear(sf::Color(50, 50, 64));

        earth.draw(window);
        rocket.draw(window);

        window.display();
        

    }
}