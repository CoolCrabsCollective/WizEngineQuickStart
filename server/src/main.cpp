#include <SFML/Network.hpp>
#include <WIZ/logging/TagLoggerWrapper.h>
#include <WIZ/logging/DateTimeLoggerWrapper.h>
#include <WIZ/logging/MultiLogger.h>
#include <WIZ/logging/DailyFileLogger.h>
#include <WIZ/logging/StdOutLogger.h>

int main()    
{
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
    sf::TcpSocket client;
    if (listener.accept(client) != sf::Socket::Done)
    {
        logger->error("Failed to accept connection");
    }

    logger->info("Client connected");

    return 0;    
}    

