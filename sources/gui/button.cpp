#include "headers/gui/button.hpp"
#include "headers/utility.hpp"

#include <iostream>

namespace GUI {

Button::Button(const Resources::FontHolder& font, const Resources::TextureHolder& textures, std::string text, sf::Vector2f position, bool selectable)
    :mCallback()
    ,mNormalTexture(textures.get(Resources::TexturesID::NormalButton))
    ,mPressedTexture(textures.get(Resources::TexturesID::PressedButton))
    ,mHoveredTexture(textures.get(Resources::TexturesID::HoveredButton))
    ,mSprite()
    ,mText(text, font.get(Resources::FontsID::Base), 16)
    ,mIsSelectable(selectable)
{
    mSprite.setTexture(mNormalTexture);

    setPosition(position);

    sf::FloatRect bounds = mSprite.getLocalBounds();
    mText.setPosition(bounds.width/2.f, bounds.height/2.f);

    Utility::centerOrigin(mText);
}


void Button::setCallback(Callback callback)
{
    mCallback = std::move(callback);
}

void Button::setText(std::string text)
{
    mText.setString(text);
    Utility::centerOrigin(mText);
}

void Button::setSelectable(bool selectable)
{
    mIsSelectable = selectable;
}

bool Button::isSelectable() const
{
    return mIsSelectable;
}

bool Button::isHoverable() const
{
    return true;
}

void Button::hover()
{
    if(isHovered() && !isActive())
        mSprite.setTexture(mHoveredTexture);
    Component::hover();
}

void Button::unhover()
{
    if(!isActive())
        mSprite.setTexture(mNormalTexture);
    Component::unhover();
}

void Button::activate()
{
    Component::activate();

    if(mIsSelectable)
        mSprite.setTexture(mPressedTexture);

    if(mCallback)
        mCallback();

    if(!mIsSelectable)
    {
        deactivate();
    }
}

void Button::deactivate()
{
    Component::deactivate();

    if(mIsSelectable)
    {
        if(isSelected())
            mSprite.setTexture(mPressedTexture);
        else
            mSprite.setTexture(mNormalTexture);
    }
}

void Button::handleEvent(const sf::Event&, sf::Vector2i)
{
    activate();
}

bool Button::checkMouseOnComponent(sf::Vector2i mousePos)
{
    if (mousePos.x>getPosition().x && mousePos.x<(getPosition().x + mSprite.getGlobalBounds().width)) {
        if(mousePos.y>getPosition().y && mousePos.y<(getPosition().y + mSprite.getGlobalBounds().height)) {
            return true;
        }
    }
    return false;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);
    target.draw(mText, states);
}

}

