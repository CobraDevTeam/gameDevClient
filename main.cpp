#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window/Mouse.hpp"
#include <memory>

#include "headers/resourcemanagement/resourceholder.hpp"
#include "headers/gui/container.hpp"
#include "headers/gui/button.hpp"

using namespace std;

int main()
{
    Resources::FontHolder fonts;
    Resources::TextureHolder textures;

    textures.load(Resources::TexturesID::NormalButton, "image.png");
    textures.load(Resources::TexturesID::PressedButton, "imagePressed.png");
    textures.load(Resources::TexturesID::SelectedButton, "imageSelected.png");

    fonts.load(Resources::FontsID::Base, "arial.ttf");

    GUI::Container container;

    auto button = make_shared<GUI::Button>(fonts, textures);
    button->setPosition(100.f,100.f);
    button->setText("Plop");
    button->setCallblack([]() {std::cout << "Lourd";});

    container.pack(button);

    sf::RenderWindow window(sf::VideoMode(640, 480), "Cobra");

    while(window.isOpen())
    {
        window.clear();
        window.draw(container);
        window.display();

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else
                container.handleEvent(event, sf::Mouse::getPosition(window));
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}
