#pragma once

#include <chrono>
#include <set>
#include <map>

#include "Object.hpp"

class Rocket : public Object
{

public:
    Rocket();

    void updatePosition();

    const sf::View &getView();

private:
    static const std::string IMAGE_PATH;

    float x;
    float y;
    float speedX;
    float speedY;
    const float a; // acceleration

    sf::View view;
    const float yBound;

    std::chrono::steady_clock::time_point time;

    typedef std::set<sf::Keyboard::Key> keyset;

    const keyset KEYS_LEFT{sf::Keyboard::A, sf::Keyboard::H, sf::Keyboard::Left};
    const keyset KEYS_RIGHT{sf::Keyboard::D, sf::Keyboard::L, sf::Keyboard::Right};
    const keyset KEYS_UP{sf::Keyboard::W, sf::Keyboard::K, sf::Keyboard::Up};
    const keyset KEYS_DOWN{sf::Keyboard::S, sf::Keyboard::J, sf::Keyboard::Down};

    const std::map<char, keyset> KEYMAP{{'L', KEYS_LEFT}, {'R', KEYS_RIGHT}, {'U', KEYS_UP}, {'D', KEYS_DOWN}};

    std::map<char, bool> getKeysState();
};