#include "headers/states/statestack.hpp"

StateStack::StateStack(State::Context context)
:mStack()
,mPendingList()
,mContext(context)
,mFactories()
{
}


void StateStack::update(sf::Time dt)
{
    // Iterate from bottom to top
    for(auto state = mStack.rbegin(); state != mStack.rend(); state++)
    {
        if(!(*state)->update(dt))
            break;
    }

    applyPendingChanges();
}

void StateStack::draw()
{
    for(auto state = mStack.begin(); state != mStack.end(); state++)
    {
        (*state)->draw();
    }
}

void StateStack::handleEvent(const sf::Event& event)
{
    // Iterate from bottom to top
    for(auto state = mStack.rbegin(); state != mStack.rend(); state++)
    {
        if(!(*state)->handleEvent(event))
            break;
    }

    applyPendingChanges();
}

void StateStack::pushState(States::ID stateID)
{
    mPendingList.push_back(PendingChange(Action::Push, stateID));
}

void StateStack::popState()
{
    mPendingList.push_back(PendingChange(Action::Pop));
}

void StateStack::clearStates()
{
    mPendingList.push_back(PendingChange(Action::Clear));
}

bool StateStack::isEmpty() const
{
    return mStack.empty();
}


State::Ptr StateStack::createState(States::ID stateID)
{
    auto found = mFactories.find(stateID);

    return found->second();
}

void StateStack::applyPendingChanges()
{
    for(auto change = mPendingList.begin(); change != mPendingList.end(); change++)
    {
        switch (change->action)
        {
        case Action::Push:
            mStack.push_back(createState(change->stateID));
            break;
        case Action::Pop:
            mStack.pop_back();
            break;
        case Action::Clear:
            mStack.clear();
            break;
        }
    }
    mPendingList.clear();
}


StateStack::PendingChange::PendingChange(Action anAction, States::ID aStateID)
:action(anAction)
,stateID(aStateID)
{

}


