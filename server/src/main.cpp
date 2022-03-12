#include <SFML/Network.hpp>
#include <WIZ/logging/TagLoggerWrapper.h>
#include <WIZ/logging/DateTimeLoggerWrapper.h>
#include <WIZ/logging/MultiLogger.h>
#include <WIZ/logging/DailyFileLogger.h>
#include <WIZ/logging/StdOutLogger.h>

#include <vector>

std::vector<sf::TcpSocket*> clients;

int main()
{
    bool isRunning = true;

    std::unique_ptr<wiz::Logger> logger = std::unique_ptr<wiz::Logger>(new wiz::TagLoggerWrapper(
            new wiz::DateTimeLoggerWrapper(
                    new wiz::MultiLogger({
                            new wiz::DailyFileLogger("logs/", wiz::LogLevel::DEBUG),
                            new wiz::StdOutLogger(wiz::LogLevel::DEBUG)
                    }), "[%H:%M:%S]")));

    logger->info("Starting test server");

    sf::TcpListener listener;

    // bind the listener to a port
    if (listener.listen(2020) != sf::Socket::Done)
    {
        logger->error("Failed to bind listener");
    }

    // accept a new connection
    while(isRunning)
    {
        sf::TcpSocket* client = new sf::TcpSocket();
        if (listener.accept(*client) != sf::Socket::Done)
        {
            logger->error("Failed to accept connection");
            delete client;
        }
        else
        {
            logger->info("Client connected");
            clients.push_back(client);
            std::string msgGreetings("What's up gamer!");
            client->send(msgGreetings.c_str(), msgGreetings.size() + 1);
        }
    }

    for(uint32_t i = 0; i < clients.size(); i++)
    {
        delete clients[i];
    }

    return 0;    
}    

