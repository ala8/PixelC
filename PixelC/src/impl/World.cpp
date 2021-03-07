#include "../headers/World.h"

World::World(sf::RenderWindow*& wnd, int blockSize[2])
    : window(wnd)
{
    this->m_blockSize[0] = blockSize[0];
    this->m_blockSize[1] = blockSize[1];

    this->m_blockPerLine = floor(this->window->getSize().x / this->m_blockSize[0]);
    this->m_blockDepth = floor(this->window->getSize().y / this->m_blockSize[1] / 2);

    this->dirtTexture.loadFromFile("Assets/img/dirt_block.png");
}

void World::InitDefWorld()
{
    this->blocks.clear();
    for (int x = 0; x < this->m_blockPerLine; x++)
    {
        for (int y = 1; y < this->m_blockDepth; y++)
        {
            this->blocks.push_back(x * this->m_blockSize[0]);
            this->blocks.push_back(this->window->getSize().y - y * this->m_blockSize[1]);
        }
    }
}

void World::RenderWorld()
{
    for (int i = 0; i < this->blocks.size(); i += 2)
    {
        int x = this->blocks[i];
        int y = this->blocks[i + 1];

        sf::Sprite sprite;
        sprite.setTexture(this->dirtTexture);
        sprite.setScale(sf::Vector2f(1.6f, 1.6f));
        sprite.setPosition(sf::Vector2f(x, y));

        this->window->draw(sprite);
    }
}

void World::WorldEvents()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i pos = sf::Mouse::getPosition(*(this->window));
        int posx = floor(pos.x / this->m_blockSize[0]) * this->m_blockSize[0];
        int posy = floor(pos.y / this->m_blockSize[1]) * this->m_blockSize[1];

        for (int i = 0; i < this->blocks.size(); i += 2)
        {
            if (blocks[i] == posx && blocks[i + 1] == posy)
            {
                this->blocks.erase(this->blocks.begin() + i);
                this->blocks.erase(this->blocks.begin() + i);
            }
        }
    }
}