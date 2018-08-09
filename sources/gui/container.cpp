#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Window/Mouse.hpp"

#include "headers/gui/container.hpp"

namespace GUI {

Container::Container()
    :mSelectedChild(0)
    ,mHoveredChild(0)
    ,mChildren()
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

bool Container::isHoverable() const
{
    return false;
}

void Container::handleEvent(const sf::Event &event, sf::Vector2i mousePos)
{
    if(event.type == sf::Event::MouseMoved)
    {
        handleHover(event, mousePos);
    }

    else if(event.type == sf::Event::MouseButtonPressed)
    {
        handleSelect(event, mousePos);
    }

    else if(event.type == sf::Event::TextEntered)
    {
        mChildren[mSelectedChild]->handleEvent(event);
    }
}

bool Container::handleHover(const sf::Event &event, sf::Vector2i mousePos)
{
    if(!mChildren[mHoveredChild]->checkMouseOnComponent(mousePos))
    {
        mChildren[mHoveredChild]->unhover();
        for(auto it = mChildren.begin(); it != mChildren.end(); it++)
        {
            if((*it)->checkMouseOnComponent(mousePos))
            {
                if((*it)->isHoverable())
                {
                    (*it)->hover();
                    mHoveredChild = std::distance(mChildren.begin(), it);
                }
            }
        }
    }
    else
    {
        mChildren[mHoveredChild]->hover();
    }
}

bool Container::handleSelect(const sf::Event &event, sf::Vector2i mousePos)
{
    for(auto it = mChildren.begin(); it != mChildren.end(); it++)
    {
        if((*it)->checkMouseOnComponent(mousePos))
        {
            (*it)->handleEvent(event, mousePos);
            if((*it)->isSelectable())
            {
                (*it)->select();
                mChildren[mSelectedChild]->deselect();
                mSelectedChild = std::distance(mChildren.begin(), it);
            }
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
