#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

class Player
{
    sf::RenderWindow* window;
    sf::Texture playerTexture;

    int blockSize[2];
    int blockDepth;

    float x;
    float y;

    bool jumping = false;
    float current_range = 0.0f;
    float jump_range = 20.0f;

    float gravityVel = 0.0f;
    
    bool movetest = false;

public:

    Player(sf::RenderWindow*& wnd, int blockSize[2]);
    void RenderPlayer();
    void PlayerEvents(sf::Time dt, std::vector<int> blocks);
    void PlayerGravity(std::vector<int> blocks);

    int groundLevel = 0;
};

