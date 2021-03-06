#include "headers/gui/textinput.hpp"
#include "headers/utility.hpp"

namespace GUI {

TextInput::TextInput(const Resources::FontHolder& font, const Resources::TextureHolder& textures, std::string text, sf::Vector2f position)
: mNormalTexture(textures.get(Resources::TexturesID::NormalButton))
, mSelectedTexture(textures.get(Resources::TexturesID::SelectedButton))
, mHoveredTexture(textures.get(Resources::TexturesID::HoveredButton))
, mSprite()
, mText(text, font.get(Resources::FontsID::Base), 16)
{
    mSprite.setTexture(mNormalTexture);

    setPosition(position);

    sf::FloatRect bounds = mSprite.getLocalBounds();
    mText.setPosition(bounds.width/2.f, bounds.height/2.f);
    mText.setStyle(sf::Text::Italic);

    Utility::centerOrigin(mText);
}

bool TextInput::isSelectable() const
{
    return true;
}

bool TextInput::isHoverable() const
{
    return true;
}

void TextInput::select()
{
    Component::select();
    Component::activate();
    mSprite.setTexture(mSelectedTexture);
}

void TextInput::deselect()
{
    Component::deactivate();
    Component::deselect();
    mSprite.setTexture(mNormalTexture);
}

void TextInput::hover()
{
    if(isHovered() && !isActive())
        mSprite.setTexture(mHoveredTexture);
    Component::hover();
}

void TextInput::unhover()
{
    if(!isActive())
        mSprite.setTexture(mNormalTexture);
    Component::unhover();
}

std::string TextInput::getText() const
{
    return mText.getString();
}

void TextInput::setText(const std::string& text)
{
    mText.setString(text);
    Utility::centerOrigin(mText);
}

void TextInput::handleEvent(const sf::Event& event, sf::Vector2i)
{
    if(event.type == sf::Event::TextEntered)
    {
        std::string str(getText());
        if(event.text.unicode == '\b')
        {
            if(str.size() > 0)
                str.erase(str.size() - 1, 1);
        }
        else if((event.text.unicode < 128 || event.text.unicode > 159) && str.size() <= 16)
            str += event.text.unicode;
        setText(str);
    }
}

bool TextInput::checkMouseOnComponent(sf::Vector2i mousePos)
{
    if (mousePos.x>getPosition().x && mousePos.x<(getPosition().x + mSprite.getGlobalBounds().width)) {
        if(mousePos.y>getPosition().y && mousePos.y<(getPosition().y + mSprite.getGlobalBounds().height)) {
            return true;
        }
    }
    return false;
}

void TextInput::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);
    target.draw(mText, states);
}

}
