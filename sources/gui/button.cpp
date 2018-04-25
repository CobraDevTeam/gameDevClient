#include "headers/gui/button.hpp"

namespace GUI {

Button::Button(const Resources::FontHolder& font, const Resources::TextureHolder& textures)
    :mCallback()
    ,mNormalTexture(textures.get(Resources::TexturesID::NormalButton))
    ,mSelectedTexture(textures.get(Resources::TexturesID::SelectedButton))
    ,mPressedTexture(textures.get(Resources::TexturesID::PressedButton))
    ,mSprite()
    ,mText("", font.get(Resources::FontsID::Base), 16)
    ,mIsToggle(false)
{
    mSprite.setTexture(mNormalTexture);

    sf::FloatRect bounds = mSprite.getLocalBounds();
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

void Button::handleEvent(const sf::Event&)
{

}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText, states);
}


}


