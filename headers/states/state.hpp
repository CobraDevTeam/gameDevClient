#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include "SFML/Window/Event.hpp"
#include "SFML/System/Time.hpp"

#include "headers/states/stateidentifier.hpp"

class StateStack;

class State
{
    public:
        typedef std::unique_ptr<State> Ptr;
        struct Context
        {

        };

    public:
                        State(StateStack& stateStack, Context context);
        virtual         ~State();

        virtual void    draw() = 0;
        virtual bool    update(sf::Time dt) = 0;
        virtual bool    handleEvent(const sf::Event& event) = 0;

    protected:
        void            requestStackPush(States::ID stateID);
        void            requestStackPop();
        void            requestStackClear();

        Context         getContext() const;

    private:
        StateStack* mStack;
        Context mContext;

};

#endif // STATE_HPP
