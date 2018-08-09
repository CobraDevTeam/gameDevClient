#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <memory>
#include <functional>
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#include "headers/gui/component.hpp"
#include "headers/resourcemanagement/resourceholder.hpp"
#include "headers/resourcemanagement/resourceidentifiers.hpp"

namespace GUI {

/**
 * @brief Composant du GUI destiné à créer des boutons
 */
class Button : public Component
{

public:
    typedef std::shared_ptr<Button> Ptr;

    typedef std::function<void()> Callback;

public:
    /**
     * @brief Constructeur, définit les textures et initialise le bouton en état normal
     */
    Button(const Resources::FontHolder& font, const Resources::TextureHolder& textures, std::string text = "", sf::Vector2f position = sf::Vector2f(0,0), bool selectable = false);

    void                    setCallback(Callback callback);
    void                    setText(std::string text);

    /**
     * @brief Détermine si le Button est poussoir ou un interrupteur
     */
    void                    setSelectable(bool selectable);
    virtual bool            isSelectable() const;

    virtual bool            isHoverable() const;
    virtual void            hover();
    virtual void            unhover();


    virtual void            activate();
    virtual void            deactivate();

    /**
     * @brief Prend en charge les interruptions et les traite : active le bouton
     */
    virtual void            handleEvent(const sf::Event&, sf::Vector2i = sf::Vector2i(0,0));

    /**
     * @brief Détermine si les coordonnées en argument sont dans la zone du component
     * @param mousePos : position de la souris dans la RenderWindow
     */
    virtual bool            checkMouseOnComponent(sf::Vector2i mousePos);

private:
    virtual void            draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    /**
     * @brief Attribut fonction de callback : fonction appelée lorsqu'on appuie sur le bouton
     */
    Callback mCallback;
    const sf::Texture&      mNormalTexture;
    const sf::Texture&      mPressedTexture;
    const sf::Texture&      mHoveredTexture;
    sf::Sprite              mSprite;
    sf::Text                mText;
    bool                    mIsSelectable;
};

}


#endif // BUTTON_HPP
