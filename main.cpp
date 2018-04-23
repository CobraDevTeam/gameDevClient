#include <iostream>
#include "SFML/Graphics.hpp"

#include "headers/resourcemanagement/resourceholder.hpp"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Cobra");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}
