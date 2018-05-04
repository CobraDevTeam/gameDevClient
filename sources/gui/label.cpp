#include "headers/gui/label.hpp"
#include <iostream>

namespace GUI {

Label::Label(const std::string& text, const Resources::FontHolder& fonts)
    :mText(text, fonts.get(Resources::FontsID::Base), 16)
{}

bool Label::isSelectable() const
{
    return false;
}

void Label::setText(const std::string &text)
{
    mText.setString(text);
}

void Label::handleEvent(const sf::Event&)
{
}

void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText, states);
}

}
