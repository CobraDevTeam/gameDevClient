#include <iostream>
#include "SFML/Graphics.hpp"

#include "headers/resourcemanagement/resourceholder.hpp"

using namespace std;

int main()
{
    Resources::ResourceHolder<sf::Texture, Resources::ID> resourceHolder;
    resourceHolder.load(Resources::ID::Bonsoir, "digit_29.png");
    cout << "Hello World!" << endl;
    return 0;
}
