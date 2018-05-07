#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "headers/connection/gateway.hpp"

class Application
{
    public:
        Application();

        void run();

    private:
        Gateway mGateway;
};

#endif // APPLICATION_HPP
