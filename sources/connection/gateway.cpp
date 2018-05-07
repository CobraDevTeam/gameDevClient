#include "headers/connection/gateway.hpp"

#include <iostream>

Gateway::Gateway(sf::IpAddress dstAddress, unsigned int dstPort)
: mConnectionAvailable(false)
{
    sf::Socket::Status status = mSocket.connect(dstAddress, dstPort);
    if(status != sf::Socket::Done)
    {
        throw std::runtime_error("Gateway Error : Failed to connect to " + dstAddress.toString() + " on port " + std::to_string(dstPort));
    }
    mConnectionAvailable = true;
    std::cout << "Connection complete" << std::endl;
}
