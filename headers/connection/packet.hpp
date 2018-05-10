#ifndef PACKET_HPP
#define PACKET_HPP

#include <SFML/Network/Packet.hpp>

/// Classe encapsulant les paquets qui seront envoyés et reçus
/**
 * À utiliser de préférence plutôt que la classe dont elle dérive, ca permettre d'implémenter facilement
 * nos propres protocoles de communication
 */
class Packet : public sf::Packet
{
};

#endif // PACKET_HPP
