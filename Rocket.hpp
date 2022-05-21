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
    float angle;
    const float a;     // engine acceleration
    const float omega; // angular speed
    const float g;     // gravity acceleration

    sf::View view;
    const float yBound;

    std::chrono::steady_clock::time_point time;  // todo switch to sf::time

    typedef std::set<sf::Keyboard::Key> keyset;

    const keyset KEYS_LEFT{sf::Keyboard::A, sf::Keyboard::H, sf::Keyboard::Left};
    const keyset KEYS_RIGHT{sf::Keyboard::D, sf::Keyboard::L, sf::Keyboard::Right};
    const keyset KEYS_UP{sf::Keyboard::W, sf::Keyboard::K, sf::Keyboard::Up, sf::Keyboard::Space};

    const std::map<char, keyset> KEYMAP{{'L', KEYS_LEFT}, {'R', KEYS_RIGHT}, {'U', KEYS_UP}};

    std::map<char, bool> getKeysState();
};