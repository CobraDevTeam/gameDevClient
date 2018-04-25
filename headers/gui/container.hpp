#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "headers/gui/component.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace GUI {

class Container : public Component
{

/**
* @brief Racine du GUI contenant tous les autres composants
*/

public:
    /**
    * @brief Constructeur, initialise le GUI vide
    */

    Container();

    /**
    * @brief Permet de rajouter au Container des Components
    */
    void                            pack(Component::Ptr component);

    /**
    * @brief Détermine si le composant peut être selectionné ou pas : ici false
    */
    virtual bool                    isSelectable() const;

    /**
     * @brief Prend en charge les interruptions et les traite : ici il les renvoie au composant selectionné
     */
    virtual void                    handleEvent(const sf::Event &event);
    virtual void                    handleEvent(const sf::Event &event, sf::Vector2i mousePos);


private:
    virtual void                    draw(sf::RenderTarget &target, sf::RenderStates states) const;


    std::vector<Component::Ptr>     mChildren;
};

}


#endif // CONTAINER_HPP
