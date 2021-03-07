#include "../headers/Player.h"

Player::Player(sf::RenderWindow*& wnd, int blockSize[2])
    : window(wnd)
{
    this->blockSize[0] = blockSize[0];
    this->blockSize[1] = blockSize[1];


    this->blockDepth = floor(this->window->getSize().y / this->blockSize[1] / 2);

    this->x = floor(this->window->getSize().x / 2 / this->blockSize[0]) * this->blockSize[0];
    this->y = this->window->getSize().y - blockDepth * this->blockSize[1];

    this->groundLevel = x + this->blockSize[1];

    this->playerTexture.loadFromFile("Assets/img/default_skin.png");
}

void Player::RenderPlayer()
{

    sf::Sprite player;
    player.setTexture(this->playerTexture);
    player.setScale(sf::Vector2f(1.6f, 1.6f));
    player.setPosition(sf::Vector2f(this->x, this->y));
    
    this->window->draw(player);
}

void Player::PlayerEvents(sf::Time dt, std::vector<int> blocks)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->x += 0.5f * dt.asMilliseconds();
        this->movetest = true;
        this->PlayerGravity(blocks);
        this->movetest = false;
        if (this->y + this->blockSize[1] > this->groundLevel)
            this->x -= 0.5f * dt.asMilliseconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->x -= 0.5f * dt.asMilliseconds();
        this->movetest = true;
        this->PlayerGravity(blocks);
        this->movetest = false;
        if (this->y + this->blockSize[1] > this->groundLevel)
            this->x += 0.5f * dt.asMilliseconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !(this->jumping))
    {
        this->jumping = true;
        this->current_range = -(this->jump_range);
    }

    if (this->jumping)
    {
        this->y += this->current_range;

        if (this->current_range >= this->jump_range)
            jumping = false;

        this->current_range++;
    }
}

void Player::PlayerGravity(std::vector<int> blocks)
{
    int posx = floor(this->x / this->blockSize[0]) * this->blockSize[0];
    int posy = floor(this->y / this->blockSize[1]) * this->blockSize[1] + this->blockSize[1];

    int highest = this->window->getSize().y;
    for (int i = 0; i < blocks.size(); i += 2)
    {
        int blockx = blocks[i];
        int blocky = blocks[i + 1];

        if (posx == blockx)
        {
            if (blocky < highest)
            {
                highest = blocky;
                this->groundLevel = blocky;
            }
        }
        if ((int)this->x % this->blockSize[0] != 0)
        {
            int posxp = floor(this->x / this->blockSize[0]) * this->blockSize[0] + this->blockSize[0];
            if (posxp == blockx)
            {
                if (blocky < highest)
                {
                    highest = blocky;
                    this->groundLevel = blocky;
                }
            }
        }
    }

    if (this->y + this->blockSize[1] < this->groundLevel && !(this->jumping))
    {
        this->y += this->gravityVel;
        this->gravityVel += 2.0f;
    }
    else if (this->gravityVel > 0.0f)
        this->gravityVel = 0.0f;
    
    if (this->y + this->blockSize[1] > this->groundLevel && !(this->movetest))
        this->y = this->groundLevel - this->blockSize[1];
}