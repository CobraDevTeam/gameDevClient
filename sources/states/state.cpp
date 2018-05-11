#include "headers/states/state.hpp"

State::State(StateStack& stateStack, Context context)
:mStack(&stateStack)
,mContext(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{

}

void State::requestStackPop()
{

}

void State::requestStackClear()
{

}

State::Context State::getContext() const
{
    return mContext;
}
