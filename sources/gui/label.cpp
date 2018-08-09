#include "headers/gui/label.hpp"
#include "headers/utility.hpp"
#include <iostream>

namespace GUI {

Label::Label(const std::string& text, const Resources::FontHolder& fonts, sf::Vector2f position)
    :mText(text, fonts.get(Resources::FontsID::Base), 16)
{
    setPosition(position);
    Utility::centerOrigin(mText);
}

bool Label::isSelectable() const
{
    return false;
}

bool Label::isHoverable() const
{
    return false;
}

void Label::setText(const std::string &text)
{
    mText.setString(text);
}

void Label::handleEvent(const sf::Event&, sf::Vector2i)
{
}

void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText, states);
}

}
