#include "headers/states/menustate.hpp"
#include "headers/gui/button.hpp"

#include "SFML/Window/Mouse.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <memory>
#include <iostream>

MenuState::MenuState(StateStack& stateStack, Context context)
:State(stateStack, context)
,mGUIContainer()
{
    sf::Texture& texture = context.mTextures->get(Resources::TexturesID::MainMenu);
    mBackGroundSprite.setTexture(texture);


    auto connectButton = std::make_shared<GUI::Button>(*context.mFonts, *context.mTextures, "Connection", sf::Vector2f(100.f, 100.f), false);
    connectButton->setCallback([this]()
    {
        requestStackPop();
        //requestStackPush(States::ID::Connection);
        std::cout << "Set state connection";
    });
    mGUIContainer.pack(connectButton);


    auto exitButton = std::make_shared<GUI::Button>(*context.mFonts, *context.mTextures, "Exit Game", sf::Vector2f(200.f, 100.f), false);
    exitButton->setCallback([this]()
    {
        requestStackPop();
    });
    mGUIContainer.pack(exitButton);

}

void MenuState::draw()
{
    sf::RenderWindow& window = *getContext().mRenderWindow;

    window.setView(window.getDefaultView());

    window.draw(mBackGroundSprite);
    window.draw(mGUIContainer);

}

bool MenuState::update(sf::Time)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
    mGUIContainer.handleEvent(event, sf::Mouse::getPosition(*getContext().mRenderWindow));
    return false;
}
