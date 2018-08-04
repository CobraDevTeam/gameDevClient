#include "headers/states/state.hpp"
#include "headers/states/statestack.hpp"


State::Context::Context(sf::RenderWindow &renderWindow, Resources::FontHolder& fonts, Resources::TextureHolder& textures, Gateway& gateway)
: mRenderWindow(&renderWindow)
, mFonts(&fonts)
, mTextures(&textures)
, mGateway(&gateway)
{

}

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
    mStack->pushState(stateID);
}

void State::requestStackPop()
{
    mStack->popState();
}

void State::requestStackClear()
{
    mStack->clearStates();
}

State::Context State::getContext() const
{
    return mContext;
}
