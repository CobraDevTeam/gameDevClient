#ifndef TEXTINPUT_HPP
#define TEXTINPUT_HPP

#include <memory>
#include <functional>
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#include "headers/gui/component.hpp"
#include "headers/resourcemanagement/resourceholder.hpp"
#include "headers/resourcemanagement/resourceidentifiers.hpp"

namespace GUI {

/**
 * @brief Composant du GUI permettant à l'utilisateur de rentrer du texte dans des champs
 */
class TextInput : public Component
{
public:
    typedef std::shared_ptr<TextInput> Ptr;

public:
    /**
    * @brief Constructeur, définit les textures et le font
    */
                                    TextInput(const Resources::FontHolder& font, const Resources::TextureHolder& textures, std::string text = "", sf::Vector2f position = sf::Vector2f(0,0));

    /**
    * @brief Détermine si le composant peut être selectionné ou pas : ici true : on sélectionne le champ puis on écrit dedans
    */
    virtual bool                    isSelectable() const;
    virtual void                    select();
    virtual void                    deselect();

    virtual bool                    isHoverable() const;
    virtual void                    hover();
    virtual void                    unhover();

    /**
    * @brief Permet de récupérer le texte tapé
    */
    std::string                     getText() const;
    void                            setText(const std::string& text);

    /**
     * @brief Prend en charge les interruptions et les traite : Ici on ne prend que du texte. La sélection est faite au niveau du container avec select();
     */
    virtual void                    handleEvent(const sf::Event& event, sf::Vector2i mousePos  = sf::Vector2i(0,0));

private:

    /**
     * @brief Détermine si les coordonnées en argument sont dans la zone du component
     * @param mousePos : position de la souris dans la RenderWindow
     */
    virtual bool                    checkMouseOnComponent(sf::Vector2i mousePos);

    void                            draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    const sf::Texture&      mNormalTexture;
    const sf::Texture&      mSelectedTexture;
    const sf::Texture&      mHoveredTexture;
    sf::Sprite              mSprite;
    sf::Text                mText;
};

}

#endif // TEXTINPUT_HPP
