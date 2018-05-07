#include "headers/gui/button.hpp"

#include <iostream>

namespace GUI {


Button::Button(const Resources::FontHolder& font, const Resources::TextureHolder& textures, Callback callback, std::string text, bool toggle, sf::Vector2f position)
    :mCallback(callback)
    ,mNormalTexture(textures.get(Resources::TexturesID::NormalButton))
    ,mSelectedTexture(textures.get(Resources::TexturesID::SelectedButton))
    ,mPressedTexture(textures.get(Resources::TexturesID::PressedButton))
    ,mSprite()
    ,mText(text, font.get(Resources::FontsID::Base), 16)
    ,mIsToggle(toggle)
{
    mSprite.setTexture(mNormalTexture);

    sf::FloatRect bounds = mSprite.getLocalBounds();
    setPosition(position);
    mText.setPosition(bounds.width/2.f, bounds.height/2.f);
}



void Button::setCallblack(Callback callback)
{
    mCallback = std::move(callback);
}

void Button::setText(std::string text)
{
    mText.setString(text);
}

void Button::setToggle(bool toggle)
{
    mIsToggle = toggle;
}

bool Button::isSelectable() const
{
    return true;
}

void Button::select()
{
    Component::select();
    mSprite.setTexture(mSelectedTexture);
}

void Button::deselect()
{
    Component::deselect();
    mSprite.setTexture(mNormalTexture);
}

void Button::activate()
{
    Component::activate();

    if(mIsToggle)
        mSprite.setTexture(mPressedTexture);

    if(mCallback)
        mCallback();

    if(!mIsToggle)
    {
        deactivate();
    }
}

void Button::deactivate()
{
    Component::deactivate();

    if(mIsToggle)
    {
        if(isSelected())
            mSprite.setTexture(mSelectedTexture);
        else
            mSprite.setTexture(mNormalTexture);
    }
}

void Button::handleEvent(const sf::Event&, sf::Vector2i)
{
    activate();
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);
    target.draw(mText, states);
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

}


