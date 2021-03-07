#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>

class World
{
    sf::RenderWindow* window;
    sf::Texture dirtTexture;

    int m_blockPerLine;
    int m_blockDepth;
    int m_blockSize[2];

public:
    
    World(sf::RenderWindow*& wnd, int blockSize[2]);
    void InitDefWorld();
    void RenderWorld();
    void WorldEvents();

    std::vector<int> blocks;
};