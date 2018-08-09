#include "headers/gui/component.hpp"

namespace GUI
{

Component::Component()
    :mIsSelected(false)
    ,mIsActive(false)
{}

Component::~Component()
{}

bool Component::isSelected() const
{
    return mIsSelected;
}

void Component::select()
{
    mIsSelected = true;
}

void Component::deselect()
{
    mIsSelected = false;
}

bool Component::isHovered() const
{
    return mIsHovered;
}

void Component::hover()
{
    mIsHovered = true;
}

void Component::unhover()
{
    mIsHovered = false;
}

bool Component::isActive() const
{
    return mIsActive;
}

void Component::activate()
{
    mIsActive = true;
}

void Component::deactivate()
{
    mIsActive = false;
}

bool Component::checkMouseOnComponent(sf::Vector2i) {
    return false;
}

}

