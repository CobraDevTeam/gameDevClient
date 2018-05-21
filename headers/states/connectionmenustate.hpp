#ifndef CONNECTIONMENUSTATE_H
#define CONNECTIONMENUSTATE_H

#include "headers/gui/container.hpp"
#include "headers/states/state.hpp"

#include "SFML/Graphics/Sprite.hpp"

class ConnectionMenuState : public State
{
    public:
                        ConnectionMenuState(StateStack& stateStack, Context context);

        virtual void    draw();
        virtual bool    update(sf::Time dt);
        virtual bool    handleEvent(const sf::Event& event);

    private:
        sf::Sprite      mBackGroundSprite;
        GUI::Container  mGUIContainer;
};

#endif // CONNECTIONMENUSTATE_H

