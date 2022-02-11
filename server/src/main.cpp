#include <SFML/Network.hpp>
#include <logging/TagLoggerWrapper.h>
#include <logging/DateTimeLoggerWrapper.h>
#include <logging/MultiLogger.h>
#include <logging/DailyFileLogger.h>
#include <logging/StdOutLogger.h>

int main()    
{
    std::unique_ptr<Logger> logger = std::unique_ptr<Logger>(new TagLoggerWrapper(
            new DateTimeLoggerWrapper(
                    new MultiLogger({
                            new DailyFileLogger("logs/", LogLevel::DEBUG),
                            new StdOutLogger(LogLevel::DEBUG)
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

