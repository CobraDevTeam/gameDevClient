#include "SFML/Graphics/RenderTarget.hpp"

#include "headers/gui/container.hpp"

namespace GUI {

Container::Container()
    :mChildren()
{
}

bool Container::isSelectable() const
{
    return false;
}

void Container::handleEvent(const sf::Event &event)
{
    // Souris handler
}

void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(auto child = mChildren.begin(); child != mChildren.end(); child++)
    {
        target.draw(**child, states);
    }
}



}
