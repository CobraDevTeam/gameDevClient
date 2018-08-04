#include "headers/connection/gateway.hpp"

#include <iostream>

Gateway::Gateway()
: mConnectionAvailable(false)
{
}

Gateway::Gateway(sf::IpAddress dstAddress, unsigned int dstPort)
: mConnectionAvailable(false)
{
    connect(dstAddress, dstPort);
}

void Gateway::connect(sf::IpAddress dstAddress, unsigned int dstPort)
{
    sf::Socket::Status status = mSocket.connect(dstAddress, dstPort);
    if(status != sf::Socket::Done)
    {
        std::cout << "Gateway Error : Failed to connect to " << dstAddress.toString() << " on port " << std::to_string(dstPort);
    }
    else {
    mConnectionAvailable = true;
    std::cout << "Connection complete to " + dstAddress.toString() + " on port " + std::to_string(dstPort) << std::endl;
}}

void Gateway::sendPacket(Packet packet)
{
    sf::Socket::Status sendStatus = mSocket.send(packet);

    switch (sendStatus) {
        case sf::Socket::Done:
            break;
        default:
            std::runtime_error("Gateway::sendPacket error");
            break;
    }
}
