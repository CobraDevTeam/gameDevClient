#ifndef RESOURCEIDENTIFIERS_HPP
#define RESOURCEIDENTIFIERS_HPP

#endif // RESOURCEIDENTIFIERS_HPP

namespace sf
{
class Texture;
class Font;
}

namespace Resources
{

/**
 * @brief Enum class listant les textures utilisées
 */
enum class TexturesID
{
    Elo,
    Bonsoir,
    Terre
};

/**
 * @brief Enum class listant les fonts utilisés
 */
enum class FontsID
{
    Base
};

template <typename Resource, typename Identifier>
class ResourceHolder;

/**
 * @brief Définition du TextureHolder
 */
typedef ResourceHolder<sf::Texture, Resources::TexturesID> TextureHolder;

/**
 * @brief Définition du FontHolder
 */
typedef ResourceHolder<sf::Font, Resources::FontsID> FontHolder;

}
