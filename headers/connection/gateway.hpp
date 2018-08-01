#ifndef GATEWAY_HPP
#define GATEWAY_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>

#include "headers/connection/packet.hpp"

class Gateway : private sf::NonCopyable
{
    public:
        Gateway();
        Gateway(sf::IpAddress dstAddress, unsigned int dstPort);

        void sendPacket(Packet packet);

    private:
        /// La socket TCP grâce à laquelle on va communiquer
        sf::TcpSocket   mSocket;

        /// Indique si la connexion est fonctionnelle
        bool            mConnectionAvailable;
};

#endif // GATEWAY_HPP
