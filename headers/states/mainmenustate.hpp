#ifndef HEADERSSTATESMENUSTATE_HPP
#define HEADERSSTATESMENUSTATE_HPP

#include "headers/gui/container.hpp"
#include "headers/states/state.hpp"

#include "SFML/Graphics/Sprite.hpp"

class MainMenuState : public State
{
    public:
                        MainMenuState(StateStack& stateStack, Context context);

        virtual void    draw();
        virtual bool    update(sf::Time dt);
        virtual bool    handleEvent(const sf::Event& event);

    private:
        sf::Sprite      mBackGroundSprite;
        GUI::Container  mGUIContainer;
};

#endif // HEADERSSTATESMENUSTATE_HPP
