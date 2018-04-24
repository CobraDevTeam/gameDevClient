#include "headers/gui/label.hpp"

namespace GUI {

Label::Label(const std::string& text, const sf::Font& font)
    :mText(text, font, 20)
{}

bool Label::isSelectable() const
{
    return false;
}

void Label::setText(const std::string &text)
{
    mText.setString(text);
}

void Label::handleEvent(const sf::Event &event)
{}

void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText, states);
}

}
