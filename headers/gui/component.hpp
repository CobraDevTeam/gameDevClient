#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/System/NonCopyable.hpp"
#include "SFML/Window/Event.hpp"

namespace GUI
{

/**
 * @brief Une classe abstraite dont va dériver toutes les composants de l'interface graphique
 */

class Component : public sf::Drawable
                , public sf::Transformable
                , private sf::NonCopyable
{
public:
    typedef std::shared_ptr<Component> Ptr;

public:

    /**
     * @brief Constructeur, initialise les deux attributs
     */
                    Component();

    virtual         ~Component();

    /**
    * @brief Détermine si le component peut être sélectionné ou pas
    */
    virtual bool    isSelectable() const = 0;

    bool            isSelected() const;
    virtual void    select();
    virtual void    deselect();
    virtual bool    isActive() const;
    virtual void    activate();
    virtual void    deactivate();

    /**
     * @brief Détermine si les coordonnées en argument sont dans la zone du component
     */
    virtual bool            checkMouseOnComponent(sf::Vector2i);

    /**
    * @brief Fonction prenant en charge les interruptions des évènements
    */
    virtual void    handleEvent(const sf::Event& event, sf::Vector2i mousePos = sf::Vector2i(0,0)) = 0;

private:
    bool mIsSelected;
    bool mIsActive;
};

}

#endif // COMPONENT_HPP
