#include "headers/states/state.hpp"
#include "headers/states/statestack.hpp"


State::Context::Context(sf::RenderWindow &renderWindow, Resources::FontHolder& fonts, Resources::TextureHolder& textures)
: mRenderWindow(&renderWindow)
, mTextures(&textures)
, mFonts(&fonts)
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
