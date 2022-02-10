#include <SFML/Network.hpp>    
    
int main()    
{    
    sf::TcpListener listener;

    // bind the listener to a port
    if (listener.listen(2020) != sf::Socket::Done)
    {
        // error...
    }

    // accept a new connection
    sf::TcpSocket client;
    if (listener.accept(client) != sf::Socket::Done)
    {
        // error...
    }

    return 0;    
}    

