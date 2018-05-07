#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

class Utility
{
    public:
        // Call setOrigin() with the center of the object
        static void centerOrigin(sf::Sprite& sprite);
        static void centerOrigin(sf::Text& text);
};


#endif // UTILITY_HPP
