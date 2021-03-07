#include "../headers/Game.h"

Game::Game(float width, float height, const char* title)
{
    this->m_window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

    // cmd thread
    auto threadLambda = [this]() {
        std::cout << "Welcome to PixelC.\n";
        std::cout << "Press return to create and enter a default world.";
        std::cin.get();

        this->message[0] = JOINWORLD;
        this->message[1] = DEFWORLD;
    };

    std::thread* cmdThread = new std::thread(threadLambda);


    // Initialization
    this->m_window->setFramerateLimit(60);

    // Game loop
    while (this->m_window->isOpen())
    {
        // Update delta time
        this->dt = this->clock.restart();

        this->Events();
        this->Render();
    }
    
    cmdThread->join();
    delete cmdThread;
    delete this->m_window;

}

void Game::Events()
{
    while (this->m_window->pollEvent(this->m_event))
    {
        switch (this->m_event.type)
        {
        case sf::Event::Closed:
            this->m_window->close();
            break;
        }
    }

    if (this->message[0] == JOINWORLD && this->message[1] == DEFWORLD)
    {
        std::cout << "Entered a default world.\n";

        this->currentWorld = new World(this->m_window, this->m_blocksize);
        this->player = new Player(this->m_window, this->m_blocksize);

        this->currentWorld->InitDefWorld();
        
        this->inWorld = true;

        this->message[0] = NULLMESSAGE;
        this->message[1] = NULLMESSAGE;
    }

    if (this->inWorld)
    {
        this->player->PlayerEvents(this->dt, this->currentWorld->blocks);
        this->player->PlayerGravity(this->currentWorld->blocks);
        this->currentWorld->WorldEvents();
    }
}

void Game::Render()
{
    this->m_window->clear();

    if (this->inWorld)
    {
        this->currentWorld->RenderWorld();
        this->player->RenderPlayer();
    }

    this->m_window->display();
}