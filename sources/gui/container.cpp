#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Window/Mouse.hpp"

#include "headers/gui/container.hpp"

namespace GUI {

Container::Container()
    :mChildren()
{
}

void Container::pack(Component::Ptr component)
{
    mChildren.push_back(component);
}

bool Container::isSelectable() const
{
    return false;
}

void Container::handleEvent(const sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        for(auto it = mChildren.begin(); it != mChildren.end(); it++)
        {
            if((*it)->checkMouseOnComponent(sf::Mouse::getPosition()))
                (*it)->handleEvent(event);
        }
    }
}

void Container::handleEvent(const sf::Event &event, sf::Vector2i mousePos)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        for(auto it = mChildren.begin(); it != mChildren.end(); it++)
        {
            if((*it)->checkMouseOnComponent(mousePos))
                (*it)->handleEvent(event);
        }
    }
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
