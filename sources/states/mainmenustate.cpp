#include "headers/states/mainmenustate.hpp"
#include "headers/gui/button.hpp"

#include "SFML/Window/Mouse.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <memory>
#include <iostream>

MainMenuState::MainMenuState(StateStack& stateStack, Context context)
:State(stateStack, context)
,mGUIContainer()
{
    sf::Texture& texture = context.mTextures->get(Resources::TexturesID::MainMenu);
    mBackGroundSprite.setTexture(texture);


    auto connectButton = std::make_shared<GUI::Button>(*context.mFonts, *context.mTextures, "Connection", sf::Vector2f(400.f, 300.f), false);
    connectButton->setCallback([this]()
    {
        requestStackPop();
        requestStackPush(States::ID::ConnectionMenu);
    });
    mGUIContainer.pack(connectButton);


    auto exitButton = std::make_shared<GUI::Button>(*context.mFonts, *context.mTextures, "Exit Game", sf::Vector2f(400.f, 400.f), false);
    exitButton->setCallback([this]()
    {
        requestStackPop();
    });
    mGUIContainer.pack(exitButton);

}

void MainMenuState::draw()
{
    sf::RenderWindow& window = *getContext().mRenderWindow;

    window.setView(window.getDefaultView());

    window.draw(mBackGroundSprite);
    window.draw(mGUIContainer);

}

bool MainMenuState::update(sf::Time)
{
    return true;
}

bool MainMenuState::handleEvent(const sf::Event& event)
{
    mGUIContainer.handleEvent(event, sf::Mouse::getPosition(*getContext().mRenderWindow));
    return false;
}
