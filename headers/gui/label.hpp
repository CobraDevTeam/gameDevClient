#ifndef LABEL_HPP
#define LABEL_HPP

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#include "headers/gui/component.hpp"
#include "headers/resourcemanagement/resourceholder.hpp"
#include "headers/resourcemanagement/resourceidentifiers.hpp"

namespace GUI {

/**
 * @brief Component du GUI destiné à afficher du texte
 */

class Label : public Component
{
public:
    typedef std::shared_ptr<Label> Ptr;

public:
    /**
     * @brief Constructeur, définit la forme et le texte
     */
                                    Label(const std::string& text, const Resources::FontHolder& font, sf::Vector2f position = sf::Vector2f(0,0));

    /**
    * @brief Détermine si le composant peut être selectionné ou pas : ici false
    */
    virtual bool                    isSelectable() const;
    virtual bool                    isHoverable() const;
    void                            setText(const std::string& text);

    /**
     * @brief Prend en charge les interruptions et les traite : ici vide, Label n'est que du texte
     */
    virtual void                    handleEvent(const sf::Event& event, sf::Vector2i mousePos = sf::Vector2i(0,0));

private:
    void                            draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Text mText;
};

}


#endif // LABEL_HPP
