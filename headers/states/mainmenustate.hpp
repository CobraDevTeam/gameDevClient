#ifndef HEADERSSTATESMENUSTATE_HPP
#define HEADERSSTATESMENUSTATE_HPP

#include "headers/gui/container.hpp"
#include "headers/states/state.hpp"

#include "SFML/Graphics/Sprite.hpp"

/**
 * @brief Etat correspondant au Menu Principal
 */
class MainMenuState : public State
{
    public:
                        MainMenuState(StateStack& stateStack, Context context);

        virtual void    draw();
        virtual bool    update(sf::Time dt);
        /**
        * @brief Méthode : Prend en charge les interruptions et les traite : les renvoie au GUIcontainer
        */
        virtual bool    handleEvent(const sf::Event& event);

    private:
        sf::Sprite      mBackGroundSprite;
        /**
         * @brief Conteneur permettant d'afficher et d'utiliser l'interface graphique
         */
        GUI::Container  mGUIContainer;
};

#endif // HEADERSSTATESMENUSTATE_HPP
