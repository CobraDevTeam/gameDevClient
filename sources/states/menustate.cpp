#include "headers/states/menustate.hpp"

#include "SFML/Window/Mouse.hpp"

MenuState::MenuState(StateStack& stateStack, Context context)
:State(stateStack, context)
,mGUIContainer()
{

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
