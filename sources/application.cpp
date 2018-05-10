#include "headers/application.hpp"

#include <iostream>

Application::Application()
: mGateway(sf::IpAddress("127.0.0.1"), 50002)
{

}

void Application::run()
{
    // Exemple d'utilisation de la connexion avec le serveur. A virer des qu'il y aura la statestack bien sur

    int x(1);
    while(x != 0)
    {
        Packet p;
        p << x;
        std::cout << "Current x:" << x << "\n";
        mGateway.sendPacket(p);
        std::cout << "Enter int:\n";
        std::cin >> x;
        std::cout << "Entered: " << x << "\n";
    }
}
