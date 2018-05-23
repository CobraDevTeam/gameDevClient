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

class TextInput : public Component
{
public:
    typedef std::shared_ptr<TextInput> Ptr;

public:
                                    TextInput(const Resources::FontHolder& font, const Resources::TextureHolder& textures, std::string text = "", sf::Vector2f position = sf::Vector2f(0,0));

    virtual bool                    isSelectable() const;

    std::string                     getText() const;
    void                            setText(const std::string& text);

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
    sf::Sprite              mSprite;
    sf::Text                mText;
};

}

#endif // TEXTINPUT_HPP
