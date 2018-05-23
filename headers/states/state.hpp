#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include "SFML/Window/Event.hpp"
#include "SFML/System/Time.hpp"

#include "headers/states/stateidentifier.hpp"
#include "headers/resourcemanagement/resourceidentifiers.hpp"

class StateStack;
namespace sf {
    class RenderWindow;
}

/**
 * @brief Classe abstraite formant la base des états de l'application
 */
class State
{
    public:
        typedef std::unique_ptr<State> Ptr;

        /**
         * @brief Structure contenant des pointeurs vers l'environnement dans lequel se situe l'état (fenêtre, resourceHolder)
         */
        struct Context
        {
                                            Context(sf::RenderWindow& renderWindow, Resources::FontHolder& fonts, Resources::TextureHolder& textures);

            sf::RenderWindow*               mRenderWindow;
            Resources::FontHolder*          mFonts;
            Resources::TextureHolder*       mTextures;
        };

    public:
        /**
         * @brief Constructeur : initialise le contexte et la pile d'état à laquelle appartient l'état
         */
                        State(StateStack& stateStack, Context context);
        virtual         ~State();

        virtual void    draw() = 0;
        virtual bool    update(sf::Time dt) = 0;
        /**
        * @brief Méthode abstraite : Prend en charge les interruptions et les traite
        */
        virtual bool    handleEvent(const sf::Event& event) = 0;

    protected:
        /**
        * @brief Méthode demandant à la pile d'état d'ajouter un nouvel état d'identifiant StateID
        * @param StateID : renvoie vers un état
        */
        void            requestStackPush(States::ID stateID);
        /**
        * @brief Méthode demandant à la pile d'état de supprimer le dernier état de la pile
        */
        void            requestStackPop();
        /**
        * @brief Méthode demandant à la pile d'état de supprimer tous les états
        */
        void            requestStackClear();

        Context         getContext() const;

    private:
        /**
         * @brief Pile d'états à laquelle appartient l'état
         */
        StateStack* mStack;
        /**
         * @brief Structure contenant des pointeurs vers l'environnement dans lequel se situe l'état (fenêtre, resourceHolder)
         */
        Context mContext;

};

#endif // STATE_HPP
