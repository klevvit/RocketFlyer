#pragma once

#include <string>
#include <chrono>
#include <set>
#include <map>

#include <SFML/Graphics.hpp>

class Rocket {

    static const std::string IMAGE_PATH;

    sf::Texture texture;
    sf::Sprite sprite;

    float x;
    float y;
    float speedX;
    float speedY;
    constexpr static float a = 100.f;

    std::chrono::steady_clock::time_point time;

    typedef std::set<sf::Keyboard::Key> keyset;

    const keyset KEYS_LEFT {sf::Keyboard::A, sf::Keyboard::H, sf::Keyboard::Left};
    const keyset KEYS_RIGHT {sf::Keyboard::D, sf::Keyboard::L, sf::Keyboard::Right};
    const keyset KEYS_UP {sf::Keyboard::W, sf::Keyboard::K, sf::Keyboard::Up};
    const keyset KEYS_DOWN {sf::Keyboard::S, sf::Keyboard::J, sf::Keyboard::Down};

    const std::map<char, keyset> KEYMAP {{'L', KEYS_LEFT}, {'R', KEYS_RIGHT}, {'U', KEYS_UP}, {'D', KEYS_DOWN}};

public:

    Rocket();

    std::map<char, bool> getKeysState();
    void updatePosition();

    void draw(sf::RenderWindow &);

};