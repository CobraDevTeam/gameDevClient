#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "headers/connection/gateway.hpp"
#include "headers/states/statestack.hpp"
#include "headers/resourcemanagement/resourceholder.hpp"
#include "SFML/Graphics.hpp"

class Application
{
    public:
        Application();

        void                        run();

    private:
        void                        registerStates();
        void                        processInput();
        void                        update(sf::Time dt);
        void                        render();


    private:
        sf::RenderWindow            mWindow;
        Resources::TextureHolder	mTextures;
        Resources::FontHolder       mFonts;

        Gateway                     mGateway;

        StateStack                  mStateStack;

};

#endif // APPLICATION_HPP
