#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <vector>

#include "World.h"
#include "Player.h"

#define NULLMESSAGE 0
#define JOINWORLD 1
#define DEFWORLD 2

class Game
{
    sf::RenderWindow* m_window;
    sf::Event m_event;

    int m_blocksize[2] = { 80, 80 };

    World* currentWorld;
    Player* player;
    bool inWorld = false;

    sf::Clock clock;
    sf::Time dt;

public:

    Game(float width, float height, const char* title);

    void Events();
    void Render();

    int message[2];
};

