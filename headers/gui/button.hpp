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


class Button : public Component
{

public:
    typedef std::shared_ptr<Button> Ptr;
    typedef std::function<void()> Callback;

public:
    /**
     * @brief Constructeur, définit les textures et initialise le bouton en état normal
     */
    Button(const Resources::FontHolder& font, const Resources::TextureHolder& textures, Callback callback = [](){}, std::string text = "", bool toggle = false, sf::Vector2f position = sf::Vector2f(0,0));

    void                    setCallblack(Callback callback);
    void                    setText(std::string text);
    /**
     * @brief Détermine si le Button est poussoir ou un interrupteur
     */
    void                    setToggle(bool toggle);

    virtual bool            isSelectable() const;
    virtual void            select();
    virtual void            deselect();

    virtual void            activate();
    virtual void            deactivate();

    /**
     * @brief Prend en charge les interruptions et les traite : active le bouton
     */
    virtual void            handleEvent(const sf::Event&, sf::Vector2i);

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
    const sf::Texture&      mSelectedTexture;
    const sf::Texture&      mPressedTexture;
    sf::Sprite              mSprite;
    sf::Text                mText;
    bool                    mIsToggle;
};

}


#endif // BUTTON_HPP
