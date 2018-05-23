#ifndef STATESTACK_H
#define STATESTACK_H

#include "SFML/System/NonCopyable.hpp"
#include <map>
#include <functional>

#include "headers/states/stateidentifier.hpp"
#include "headers/states/state.hpp"


/**
* @brief Classe : Pile d'états. Contient les différents états dans lesquels se place l'application
*/
class StateStack : private sf::NonCopyable
{
    public:
        enum class Action
        {
            Push,
            Pop,
            Clear
        };

    public:
        /**
        * @brief Constructeur initialisant la pile d'état
        * @param Context : contient des pointeurs vers l'environnement dans lequel se situent les états de la pile (fenêtre, resourceHolder)
        */
        explicit                    StateStack(State::Context context);

        /**
        * @brief Référence les états en fonction de l'identifiant
        * @param Typename T : type d'état
        * @param StateID : identifiant correspondant à l'état T
        */
        template <typename T>
        void                        registerState(States::ID stateID);

        void                        update(sf::Time dt);
        void                        draw();
        /**
        * @brief Prend en charge les interruptions et les traite en les renvoyant aux états du haut de la pile en bas
        */
        void                        handleEvent(const sf::Event& event);

        /**
        * @brief Ajoute l'état correspondant à StateID à la pile
        * @param StateID : identifiant correspondant à un  type d'état
        */
        void                        pushState(States::ID stateID);

        /**
        * @brief Supprime le dernier état de la pile
        */
        void                        popState();

        /**
        * @brief Supprime tous les états de la pile
        */
        void                        clearStates();

        bool                        isEmpty() const;

    private:
        /**
        * @brief Crée l'état correspondant à StateID et le référence dans mFactories
        * @param StateID : identifiant correspondant à un type d'état
        */
        State::Ptr                  createState(States::ID stateID);

        /**
        * @brief Applique toutes les requêtes de changements d'états demandés par les divers états de la pile
        */
        void                        applyPendingChanges();

    private:
        /**
        * @brief Struct correspondant à une action à effectuer sur un état référencé par StateID : pop, push, clear
        */
        struct PendingChange
        {
                explicit                PendingChange(Action anAction, States::ID aStateID = States::ID::None);

                Action                  action;
                States::ID              stateID;
        };

    private:
        // Correspond à la pile d'états
        std::vector<State::Ptr>                                 mStack;
        // Correspond à la liste des changements à effectuer
        std::vector<PendingChange>                              mPendingList;

        // Correspond à l'environnement dans lequel se situent les états de la pile (fenêtre, resourceHolder)
        State::Context                                          mContext;
        // Map contenant les états créés en fonction des StateID. Fait le lien entre les états et leur identifiant
        std::map<States::ID, std::function<State::Ptr()>>       mFactories;

};

template <typename T>
void StateStack::registerState(States::ID stateID)
{
    mFactories[stateID] = [this] ()
    {
        return State::Ptr(new T(*this, mContext));
    };
}


#endif // STATESTACK_H
