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
    virtual bool                    isHoverable() const;

    /**
     * @brief Prend en charge les interruptions et les traite : ici il les renvoie au composant selectionné
     * @param mousePos : prend en argument la position de la souris par rapport à la sf::RenderWindow qui possède le container
     */
    virtual void                    handleEvent(const sf::Event &event, sf::Vector2i mousePos = sf::Vector2i(0,0));


private:
    virtual void                    draw(sf::RenderTarget &target, sf::RenderStates states) const;

    bool                            handleHover(const sf::Event &event, sf::Vector2i mousePos);
    bool                            handleSelect(const sf::Event &event, sf::Vector2i mousePos);

    int                             mSelectedChild;
    int                             mHoveredChild;
    std::vector<Component::Ptr>     mChildren;

};

}


#endif // CONTAINER_HPP
