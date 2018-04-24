#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "headers/gui/component.hpp"

namespace GUI {

class Container : public Component
{
public:
    Container();

    void                            pack(Component::Ptr component);

    virtual bool                    isSelectable() const;
    virtual void                    handleEvent(const sf::Event &event);

private:
    virtual void                    draw(sf::RenderTarget &target, sf::RenderStates states) const;

    std::vector<Component::Ptr>     mChildren;
};

}


#endif // CONTAINER_HPP
