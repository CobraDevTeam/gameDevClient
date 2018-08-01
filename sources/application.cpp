#include "headers/application.hpp"
#include "headers/states/mainmenustate.hpp"
#include "headers/states/connectionmenustate.hpp"

#include <iostream>

Application::Application()
: mWindow(sf::VideoMode(1152, 648), "Cobra")
, mTextures()
, mFonts()
, mGateway() //sf::IpAddress("127.0.0.1"), 50002
, mStateStack(State::Context(mWindow, mFonts, mTextures))
{
    // Load base resources
    mFonts.load(Resources::FontsID::Base, "arial.ttf");

    mTextures.load(Resources::TexturesID::NormalButton, "image.png");
    mTextures.load(Resources::TexturesID::PressedButton, "imagePressed.png");
    mTextures.load(Resources::TexturesID::SelectedButton, "imageSelected.png");
    mTextures.load(Resources::TexturesID::MainMenu, "mainMenu.jpg");

    registerStates();
    mStateStack.pushState(States::ID::MainMenu);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::Time timePerFrame = sf::seconds(1.f/30.f);

    while(mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;

        while(timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            processInput();
            update(timePerFrame);

            if (mStateStack.isEmpty())
                mWindow.close();
        }

    render();
    }
}

void Application::registerStates()
{
    mStateStack.registerState<MainMenuState>(States::ID::MainMenu);
    mStateStack.registerState<ConnectionMenuState>(States::ID::ConnectionMenu);
}

void Application::processInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        mStateStack.handleEvent(event);
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Application::update(sf::Time dt)
{
    mStateStack.update(dt);
}

void Application::render()
{
    mWindow.clear();

    mStateStack.draw();

    mWindow.display();
}

/*
    // Exemple d'utilisation de la connexion avec le serveur. A virer des qu'il y aura la statestack bien sur

    int x(1);
    while(x != 0)
    {
        Packet p;
        p << x;
        std::cout << "Current x:" << x << "\n";
        mGateway.sendPacket(p);
        std::cout << "Enter int:\n";
        std::cin >> x;
        std::cout << "Entered: " << x << "\n";
    }

*/
