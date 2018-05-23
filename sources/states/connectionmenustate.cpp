#include "headers/states/connectionmenustate.hpp"
#include "headers/gui/button.hpp"
#include "headers/gui/textinput.hpp"

#include "SFML/Window/Mouse.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <memory>
#include <iostream>

ConnectionMenuState::ConnectionMenuState(StateStack& stateStack, Context context)
:State(stateStack, context)
,mGUIContainer()
{
    sf::Texture& texture = context.mTextures->get(Resources::TexturesID::MainMenu);
    mBackGroundSprite.setTexture(texture);


    auto connectButton = std::make_shared<GUI::Button>(*context.mFonts, *context.mTextures, "Connect to server", sf::Vector2f(400.f, 300.f), false);
    connectButton->setCallback([this]()
    {
        std::cout << "gg";
    });
    mGUIContainer.pack(connectButton);


    auto exitButton = std::make_shared<GUI::Button>(*context.mFonts, *context.mTextures, "Back", sf::Vector2f(400.f, 400.f), false);
    exitButton->setCallback([this]()
    {
        requestStackPop();
        requestStackPush(States::ID::MainMenu);
    });
    mGUIContainer.pack(exitButton);

    auto textInput = std::make_shared<GUI::TextInput>(*context.mFonts, *context.mTextures, "Bwa", sf::Vector2f(400.f, 500.f));
    mGUIContainer.pack(textInput);

}

void ConnectionMenuState::draw()
{
    sf::RenderWindow& window = *getContext().mRenderWindow;

    window.setView(window.getDefaultView());

    window.draw(mBackGroundSprite);
    window.draw(mGUIContainer);

}

bool ConnectionMenuState::update(sf::Time)
{
    return true;
}

bool ConnectionMenuState::handleEvent(const sf::Event& event)
{
    mGUIContainer.handleEvent(event, sf::Mouse::getPosition(*getContext().mRenderWindow));
    return false;
}
